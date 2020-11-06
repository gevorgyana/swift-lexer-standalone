// Violent X macros usage, inspired by the Swift and Clang teams.
// This is metaprogramming anyway ;)

// As they are using StringRef in their code, and I don't want to break ODR,
// I should just make sure the compiler knows what that is. This is a workaround, though.
#include "llvm/ADT/StringRef.h"
using namespace llvm;

// this defines the Swift token enum
#include "swift/Syntax/TokenKinds.h"
#include "clang/Basic/TokenKinds.h"

#define TOKEN(X) \
  case swift::tok::X: return clang::tok::TokenKind::X;

int main() {
  auto foo = swift::tok::eof;
  switch(foo) {
    #include "swift/Syntax/TokenKinds.def"
    NUM_TOKENS
  }
}
