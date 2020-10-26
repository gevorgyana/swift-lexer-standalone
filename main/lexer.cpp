#include "Lexer.h"
#include "swift/Basic/LangOptions.h"

int main() {
  swift::LangOptions langOpts;
  std::string contents("hello world");
  swift::LexerMode lexMode;
  swift::Lexer L(
      langOpts,
      contents,
      lexMode
  );
  return 0;
}
