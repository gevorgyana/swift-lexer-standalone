#include "lexer.h"

#include "Lexer.h"
#include "swift/Basic/LangOptions.h"
#include "clang/Lex/Token.h"
#include "shim.h"

#include <fstream>
#include <string>
#include <iostream>

/**
 * Takes the token from a const char* and retrieves a Token in clang form. See
 * the shim.cpp for how it is done.
 **/

__attribute__((noinline)) size_t get_me_some_swift_lexeme(const char* source, clang::tok::TokenKind& Result) {

  auto copy = source;

  if (*copy == '\n') {
    std::cout << "NEWLINE" << std::endl;
  }

  if ((*copy == ' ') || (*copy == '\t')) {
    ++copy;
    while ((*copy == ' ') || (*copy == '\t'))
      ++copy;
  }

  if (copy - source > 0) {
    std::cout << "SPACES: " << copy - source << std::endl;
  }

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

/**
 * Tokenize the whole file into "results.lex",
 * where each line will contain a pair of (TokenType, TokenLength)
 * TokenType will be of type string
 **/

#define TOK(id)					\
  #id,
static const char* CLANG_TOKEN_STRING_REPR[] = {
#include "clang/Basic/TokenKinds.def"
#undef TOKEN
};

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

    // Here, we need to esace manually whitespace and other stuff like \v \t
    // Code inspired by what I did in the swift fork

    // Small amounts of horizontal whitespace is very common between tokens.
    /*
    */

    L.lex(Tok, LeadingTrivia, TrailingTrivia);
    auto in_clang_terms = shim(Tok.getKind());

    std::cout <<
      CLANG_TOKEN_STRING_REPR[in_clang_terms] << " " << Tok.getText().size() << std::endl;

  } while (Tok.getKind() != swift::tok::eof);
  return 0;
}
