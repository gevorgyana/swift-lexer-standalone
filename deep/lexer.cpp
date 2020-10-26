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
#include "swift/Frontend/Frontend.h"

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

  // SourceManager, BufferID is what we need to be able to use Lexer
  // As lldb points, only clang::SourceManager is being created. this
  // is CLEARLY coming from ClangImporter.

  // First, lldb shows that clang::Parser is called, but that makes
  // no sense to me, I am not interested. Then, it enters swift::Parser
  // And it grows the stack 3 times, which means that we enter
  // overloaded functions. Conclusion: Just skip the first breakpoint,
  // then see what happens above swift::Parser.

  // It is coming thru ParseSourceFileRequest. So need to track that.
  // Everything happens inside performSemaUpTo() inside CompilerInstance
  // the swift::CompilerInstance, not clang's!!!
  // SourceFile is created 1 time and it is done there!!!!
  // this is in Frontend.cpp file

  // this is called from performCompiler in
  // ForntendTool/FrontendTool.cpp

  // PerformSemaUpTo(SourceFile::TypeChecked) is the stage that we need



  /////////////////
  /// Okay makes more sense now.
  /// First, we go setUpModuleLoaders(), then we do file manipulations
  /// and reach clang::SourceManager, along with SourceFiles and
  /// buffers. ASTContext is set up separately.

  /// ForntendTool is the main entry point, everything else is utility.

  /// First, compiler instance is created, second, compilation is
  /// triggered


  /// Need a CompilerInstance, call everything its env. calls on it,
  /// then call performSemaUpTo. The next thing will be refine that
  /// monolith.

  std::unique_ptr<swift::CompilerInstance> Instance =
      std::make_unique<swift::CompilerInstance>();

  /// If we have this binary call Parser() or Lexer(), then we can
  /// start splitting this binary instead of doing the bigger job
  /// of splitting the whole Swift

  /// Invocation is needed to run CompilerInstance, but it jsut contains
  /// configuration files, I am still sure I can do without it. For
  /// that, I will need to see how CompilerInsance works.

  return 0;
}
