#include "lexer.h"

#include "Lexer.h"
#include "swift/Basic/LangOptions.h"
#include "clang/Lex/Token.h"
#include "shim.h"

#include <fstream>
#include <string>
#include <iostream>

/**
 * Here, we need to esace manually whitespace and other stuff like \v \t
 * Code inspired by what I did in the swift fork
 * Takes the token from a const char* and retrieves a Token in clang form. See
 * the shim.cpp for how it is done.
 **/

__attribute__((noinline)) size_t get_me_some_swift_lexeme(const char* source, clang::tok::TokenKind& Result, size_t &offset) {

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
  offset += Tok.getText().size();
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

  size_t offset = 0;
  clang::tok::TokenKind in_clang_terms;
  do {
    auto token_length = get_me_some_swift_lexeme(contents.c_str() + offset, in_clang_terms, offset);
    std::cout <<
      CLANG_TOKEN_STRING_REPR[in_clang_terms] << " " << token_length << std::endl;

  } while (in_clang_terms != clang::tok::TokenKind::eof);
  return 0;
}
