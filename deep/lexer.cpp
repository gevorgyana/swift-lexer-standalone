#include "swift/Basic/SourceManager.h"
#include "swift/Basic/LangOptions.h"
#include "swift/AST/ASTContext.h"
#include "swift/AST/DiagnosticEngine.h"

/// Use Swift Lexer

/*
                    swift::SourceManager
                                  \/
  swift::ast::ASTContext - needs SourceManager, Opt*-like classes,
               and DiagnosticEngine

 */

int main() {
  swift::SourceManager mgr;
  swift::DiagnosticEngine eng(mgr);
  swift::LangOptions lang_opts;
  swift::TypeCheckerOptions tch_opts;
  swift::SearchPathOptions sp_opts;
  swift::ASTContext::get(lang_opts, tch_opts, sp_opts, mgr, eng);
  return 0;
}
