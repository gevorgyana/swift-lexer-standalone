#include "Lexer.h"
#include "swift/Basic/LangOptions.h"

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
  } while (Tok.getKind() != swift::tok::eof);
  return 0;
}
