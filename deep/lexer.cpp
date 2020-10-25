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
  std::cout << in.file();

  swift::DiagnosticEngine eng(mgr);
  swift::LangOptions lang_opts;
  swift::TypeCheckerOptions tch_opts;
  swift::SearchPathOptions sp_opts;
  swift::ASTContext::get(lang_opts, tch_opts, sp_opts, mgr, eng);
  return 0;
}
