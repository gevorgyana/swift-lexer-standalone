// Violent X macros usage, inspired by the Swift and Clang teams.
// This is metaprogramming anyway ;)

// As they are using StringRef in their code, and I don't want to break ODR,
// I should just make sure the compiler knows what that is. This is a workaround, though.
#include "llvm/ADT/StringRef.h"
using namespace llvm;
// this defines the Swift token enum
#include "swift/Syntax/TokenKinds.h"

// But we will have to redefine Clang Tokens
// #include "clang/Basic/TokenKinds.h"

#include "llvm/ADT/StringSwitch.h"
#include <iostream>

// hijack TokenKind
namespace clang {
  namespace tok {
    enum TokenKind: unsigned short {
#define TOK(X) X,
				    // part of the tokens is already in clang
#include "clang/Basic/TokenKinds.def"
#undef TOK
				    // And those that are specific to Swift have to be translated
				    // verbatium
				    // What is marked with CTO is for compile time only
				    // which means that these tokens will be remapped thanks to
				    // the RuntimeSwitch below
				    kw_repeat,
				    kw_in,
				    kw_fallthrough,
				    kw_where,
				    kw_as,
				    kw_Any,
				    kw_is,
				    kw_nil,
				    kw_rethrows,
				    kw_super,
				    kw_self,
				    kw_Self,
				    kw_throws,
				    kw___FILE__,
				    kw___LINE__,
				    kw___COLUMN__,
				    kw___DSO_HANDLE__,
				    kw__,
				    // CTO
				    l_angle,
				    // CTO
				    r_angle,
				    period_prefix,
				    at_sign,
				    pound,
				    amp_prefix,
				    backtick,
				    backslash,
				    exclaim_postfix,
				    question_postfix,
				    question_infix,
				    string_quote,
				    single_quote,
				    multiline_string_quote,
				    pound_keyPath,
				    pound_line,
				    pound_selector,
				    pound_file,
				    pound_fileID,
				    pound_filePath,
				    pound_column,
				    pound_function,
				    pound_dsohandle,
				    pound_assert,
				    pound_sourceLocation,
				    pound_warning,
				    pound_error,
				    pound_if,
				    pound_elseif,
				    pound_endif,
				    pound_available,
				    pound_fileLiteral,
				    pound_imageLiteral,
				    pound_colorLiteral,
				    integer_literal,
				    floating_literal,
				    oper_binary_unspaced,
				    oper_binary_spaced,
				    oper_postfix,
				    oper_prefix,
				    dollarident,
				    contextual_keyword,
				    raw_string_delimiter,
				    string_segment,
				    string_interpolation_anchor,
				    kw_yield,
				    kw_undef,
				    kw_sil,
				    kw_sil_stage,
				    kw_sil_property,
				    kw_sil_vtable,
				    kw_sil_global,
				    kw_sil_witness_table,
				    kw_sil_default_witness_table,
				    kw_sil_differentiability_witness,
				    kw_sil_coverage_map,
				    kw_sil_scope,
				    sil_dollar,
				    sil_exclamation,
				    code_complete,
				    sil_local_name,
				    pound_else,
				    kw_guard,
				    kw_defer,
				    kw_internal,
				    kw_fileprivate,
				    kw_var,
				    kw_typealias,
				    kw_subscript,
				    kw_protocol,
				    kw_precedencegroup,
				    kw_let,
				    kw_inout,
				    kw_init,
				    kw_func,
				    kw_extension,
				    kw_deinit,
				    kw_associatedtype,
				    NUM_TOKENS
    };
  }
}

// Visit all Swift tokens and convert them into a string value
#define TOKEN(id)				\
  #id,
static char const* SWIFT_TOKEN_STRING_REPR[] = {
#include "swift/Syntax/TokenKinds.def"
#undef TOKEN
};

clang::tok::TokenKind shim(swift::tok SwiftTok) {
  // First of all, we should convert the numeric value that we have to
  // a string. For that, we have defined the swift token in string form
  auto SwiftTokStr =  SWIFT_TOKEN_STRING_REPR[static_cast<unsigned short>(SwiftTok)];

  // From the compiler's point of view, it is all good, because we do have all of
  // the necessary tokens types in clang as we have extended them above
  // But we won't need everything, but some of the characters have to be remapped.
  // Which is why we use a Runtime switch with a checker built into it.
  auto RuntimeSwitch =
    llvm::StringSwitch<clang::tok::TokenKind>(StringRef(SwiftTokStr));

#define TOKEN(id)						\
  if (strcmp(#id, "l_angle") != 0 && strcmp(#id, "r_angle") != 0) {		\
    RuntimeSwitch.Case(#id, clang::tok::TokenKind::id);		\
  }
#include "swift/Syntax/TokenKinds.def"
  RuntimeSwitch.Case("l_angle", clang::tok::TokenKind::pound);
  RuntimeSwitch.Case("r_angle", clang::tok::TokenKind::pound);
  return RuntimeSwitch.Default(clang::tok::TokenKind::pound);
}

/*
int main() {
  return 0;
}

*/
