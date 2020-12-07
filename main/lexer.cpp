#include "lexer.h"

#include "Lexer.h"
#include "swift/Basic/LangOptions.h"
#include "clang/Lex/Token.h"
#include "shim.h"

#include <fstream>
#include <string>
#include <iostream>

__attribute__((noinline)) size_t get_me_some_swift_lexeme(const char* source, clang::tok::TokenKind& Result) {
  swift::LangOptions langOpts;
  std::string contents(source);
  // std::cout << contents << std::endl;
  // TOOD should I initialize it? It works without it, so maybe not.
  swift::LexerMode lexMode;
  swift::SourceManager SM;
  swift::Lexer L(
      langOpts,
      SM,
      contents,
      lexMode
  );
  swift::Token Tok;
  swift::ParsedTrivia LeadingTrivia, TrailingTrivia;
  L.lex(Tok, LeadingTrivia, TrailingTrivia);
  auto in_clang_terms = shim(Tok.getKind());
  Result = in_clang_terms;
  return Tok.getText().size();
}






/*
#include "Lexer.h"
#include "swift/Basic/LangOptions.h"
#include "shim.h"

#include <fstream>
#include <string>
#include <iostream>

int main() {
  swift::LangOptions langOpts;
  std::ifstream ifs("test/main.swift");
  std::string contents(
      (std::istreambuf_iterator<char>(ifs)),
      (std::istreambuf_iterator<char>())
  );
  std::cout << contents << std::endl;
  swift::LexerMode lexMode;
  swift::SourceManager SM;
  swift::Lexer L(
      langOpts,
      SM,
      contents,
      lexMode
  );
  swift::Token Tok;
  swift::ParsedTrivia LeadingTrivia, TrailingTrivia;
  do {
    L.lex(Tok, LeadingTrivia, TrailingTrivia);
    auto in_clang_terms = shim(Tok.getKind());
  } while (Tok.getKind() != swift::tok::eof);
  return 0;
}
*/
