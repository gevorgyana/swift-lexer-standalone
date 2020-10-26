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
  swift::Lexer L(
      langOpts,
      contents,
      lexMode
  );
  return 0;
}
