#include "swift/Basic/SourceManager.h"
#include "swift/Basic/LangOptions.h"
#include "swift/AST/ASTContext.h"
#include "swift/AST/DiagnosticEngine.h"
#include "swift/Frontend/InputFile.h"

/// Use Swift Lexer

/*
                    swift::SourceManager
                                  \/
  swift::ast::ASTContext - needs SourceManager, Opt*-like classes,
               and DiagnosticEngine

 */

#include <iostream>

int main() {
  swift::SourceManager mgr;

  // from CompilerInstance::setUpInputs(), we have to
  // use CompilerInstance::setUpInput(InputFile*)
  // set up InputFile first
  // It needs a llvm::MemoryBuffer and string arguments
  /*
    InputFile(StringRef name, bool isPrimary,
            llvm::MemoryBuffer *buffer = nullptr,
            StringRef outputFilename = StringRef())
  */

  // Nothing is primary here
  swift::InputFile in("main.swift", false);
  std::cout << in.file() << std::endl;
  std::cout << in.buffer() << std::endl;
  // clangimporter::create
  swift::DiagnosticEngine eng(mgr);
  swift::LangOptions lang_opts;
  swift::TypeCheckerOptions tch_opts;
  swift::SearchPathOptions sp_opts;
  swift::ASTContext::get(lang_opts, tch_opts, sp_opts, mgr, eng);

  // now that we have a valid context, we can do what
  // ClangImporter::create() does.

  // SourceManager, BufferID
  // 1 - get bufferid from source manager inside astcontext???
  // 2 - how tf we initialize source files?????? memory buffer is still
  // empty!!!
  return 0;
}
