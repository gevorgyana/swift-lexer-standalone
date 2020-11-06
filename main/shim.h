// convert swift tokens to clang tokens

#include "swift/Syntax/TokenSyntax.h"
#include "clang/Basic/TokenKinds.h"

clang::tok::TokenKind shim(swift::tok kind);
