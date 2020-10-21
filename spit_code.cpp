#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/Version.h"
#include "clang/Format/Format.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/Process.h"

using namespace llvm;
using namespace clang;

static cl::OptionCategory ClangFormatCategory("this is it");
static cl::list<unsigned>
    Offsets("offset",
            cl::desc("Format a range starting at this byte offset.\n"
                     "Multiple ranges can be formatted by specifying\n"
                     "several -offset and -length pairs.\n"
                     "Can only be used with one input file."),
            cl::cat(ClangFormatCategory));
static cl::list<unsigned>
    Lengths("length",
            cl::desc("Format a range of this length (in bytes).\n"
                     "Multiple ranges can be formatted by specifying\n"
                     "several -offset and -length pairs.\n"
                     "When only a single -offset is specified without\n"
                     "-length, clang-format will format up to the end\n"
                     "of the file.\n"
                     "Can only be used with one input file."),
            cl::cat(ClangFormatCategory));
static cl::list<std::string>
    LineRanges("lines",
               cl::desc("<start line>:<end line> - format a range of\n"
                        "lines (both 1-based).\n"
                        "Multiple ranges can be formatted by specifying\n"
                        "several -lines arguments.\n"
                        "Can't be used with -offset and -length.\n"
                        "Can only be used with one input file."),
               cl::cat(ClangFormatCategory));

// Parses <start line>:<end line> input to a pair of line numbers.
// Returns true on error.
static bool parseLineRange(StringRef Input, unsigned &FromLine,
                           unsigned &ToLine) {
  std::pair<StringRef, StringRef> LineRange = Input.split(':');
  return LineRange.first.getAsInteger(0, FromLine) ||
         LineRange.second.getAsInteger(0, ToLine);
}

static FileID createInMemoryFile(StringRef FileName, MemoryBuffer *Source,
                                 SourceManager &Sources, FileManager &Files,
                                 llvm::vfs::InMemoryFileSystem *MemFS) {
  MemFS->addFileNoOwn(FileName, 0, Source);
  auto File = Files.getFile(FileName);
  return Sources.createFileID(File ? *File : nullptr, SourceLocation(),
                              SrcMgr::C_User);
}

static bool fillRanges(MemoryBuffer *Code,
                       std::vector<clang::tooling::Range> &Ranges) {
  IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> InMemoryFileSystem(
      new llvm::vfs::InMemoryFileSystem);
  FileManager Files(FileSystemOptions(), InMemoryFileSystem);
  DiagnosticsEngine Diagnostics(
      IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs),
      new DiagnosticOptions);
  SourceManager Sources(Diagnostics, Files);
  FileID ID = createInMemoryFile("<irrelevant>", Code, Sources, Files,
                                 InMemoryFileSystem.get());
  if (!LineRanges.empty()) {
    if (!Offsets.empty() || !Lengths.empty()) {
      errs() << "error: cannot use -lines with -offset/-length\n";
      return true;
    }

    for (unsigned i = 0, e = LineRanges.size(); i < e; ++i) {
      unsigned FromLine, ToLine;
      if (parseLineRange(LineRanges[i], FromLine, ToLine)) {
        errs() << "error: invalid <start line>:<end line> pair\n";
        return true;
      }
      if (FromLine > ToLine) {
        errs() << "error: start line should be less than end line\n";
        return true;
      }
      SourceLocation Start = Sources.translateLineCol(ID, FromLine, 1);
      SourceLocation End = Sources.translateLineCol(ID, ToLine, UINT_MAX);
      if (Start.isInvalid() || End.isInvalid())
        return true;
      unsigned Offset = Sources.getFileOffset(Start);
      unsigned Length = Sources.getFileOffset(End) - Offset;
      Ranges.push_back(clang::tooling::Range(Offset, Length));
    }
    return false;
  }

  if (Offsets.empty())
    Offsets.push_back(0);
  if (Offsets.size() != Lengths.size() &&
      !(Offsets.size() == 1 && Lengths.empty())) {
    errs() << "error: number of -offset and -length arguments must match.\n";
    return true;
  }
  for (unsigned i = 0, e = Offsets.size(); i != e; ++i) {
    if (Offsets[i] >= Code->getBufferSize()) {
      errs() << "error: offset " << Offsets[i] << " is outside the file\n";
      return true;
    }
    SourceLocation Start =
        Sources.getLocForStartOfFile(ID).getLocWithOffset(Offsets[i]);
    SourceLocation End;
    if (i < Lengths.size()) {
      if (Offsets[i] + Lengths[i] > Code->getBufferSize()) {
        errs() << "error: invalid length " << Lengths[i]
               << ", offset + length (" << Offsets[i] + Lengths[i]
               << ") is outside the file.\n";
        return true;
      }
      End = Start.getLocWithOffset(Lengths[i]);
    } else {
      End = Sources.getLocForEndOfFile(ID);
    }
    unsigned Offset = Sources.getFileOffset(Start);
    unsigned Length = Sources.getFileOffset(End) - Offset;
    Ranges.push_back(clang::tooling::Range(Offset, Length));
  }
  return false;
}

static bool format(StringRef FileName) {
  // On Windows, overwriting a file with an open file mapping doesn't work,
  // so read the whole file into memory when formatting in-place.
  ErrorOr<std::unique_ptr<MemoryBuffer>> CodeOrErr
      = MemoryBuffer::getFileAsStream(FileName);
  if (std::error_code EC = CodeOrErr.getError()) {
    errs() << EC.message() << "\n";
    return true;
  }

  std::unique_ptr<llvm::MemoryBuffer> Code = std::move(CodeOrErr.get());
  if (Code->getBufferSize() == 0)
    return false; // Empty files are formatted correctly.

  StringRef BufStr = Code->getBuffer();

  std::vector<clang::tooling::Range> Ranges;
  if (fillRanges(Code.get(), Ranges))
    return true;

  /*
  StringRef AssumedFileName = (FileName == "-") ? AssumeFileName : FileName;
  if (AssumedFileName.empty()) {
    llvm::errs() << "error: empty filenames are not allowed\n";
    return true;
  }

  llvm::Expected<FormatStyle> FormatStyle =
      getStyle(Style, AssumedFileName, FallbackStyle, Code->getBuffer());
  if (!FormatStyle) {
    llvm::errs() << llvm::toString(FormatStyle.takeError()) << "\n";
    return true;
  }

  if (SortIncludes.getNumOccurrences() != 0)
    FormatStyle->SortIncludes = SortIncludes;
  unsigned CursorPosition = Cursor;
  Replacements Replaces = sortIncludes(*FormatStyle, Code->getBuffer(), Ranges,
                                       AssumedFileName, &CursorPosition);
  auto ChangedCode = tooling::applyAllReplacements(Code->getBuffer(), Replaces);
  if (!ChangedCode) {
    llvm::errs() << llvm::toString(ChangedCode.takeError()) << "\n";
    return true;
  }
  // Get new affected ranges after sorting `#includes`.
  Ranges = tooling::calculateRangesAfterReplacements(Replaces, Ranges);
  FormattingAttemptStatus Status;
  Replacements FormatChanges =
      reformat(*FormatStyle, *ChangedCode, Ranges, AssumedFileName, &Status);
  Replaces = Replaces.merge(FormatChanges);
  if (OutputXML || DryRun) {
    if (DryRun) {
      return emitReplacementWarnings(Replaces, AssumedFileName, Code);
    } else {
      outputXML(Replaces, FormatChanges, Status, Cursor, CursorPosition);
    }
  } else {
    IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> InMemoryFileSystem(
        new llvm::vfs::InMemoryFileSystem);
    FileManager Files(FileSystemOptions(), InMemoryFileSystem);
    DiagnosticsEngine Diagnostics(
        IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs),
        new DiagnosticOptions);
    SourceManager Sources(Diagnostics, Files);
    FileID ID = createInMemoryFile(AssumedFileName, Code.get(), Sources, Files,
                                   InMemoryFileSystem.get());
    Rewriter Rewrite(Sources, LangOptions());
    tooling::applyAllReplacements(Replaces, Rewrite);
    if (Inplace) {
      if (Rewrite.overwriteChangedFiles())
        return true;
    } else {
      if (Cursor.getNumOccurrences() != 0) {
        outs() << "{ \"Cursor\": "
               << FormatChanges.getShiftedCodePosition(CursorPosition)
               << ", \"IncompleteFormat\": "
               << (Status.FormatComplete ? "false" : "true");
        if (!Status.FormatComplete)
          outs() << ", \"Line\": " << Status.Line;
        outs() << " }\n";
      }
      Rewrite.getEditBuffer(ID).write(outs());
    }
  }
  return false;
  */
}
