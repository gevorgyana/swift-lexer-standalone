// convert swift tokens to clang tokens

#include "swift/Syntax/TokenSyntax.h"
#include "clang/Basic/TokenKinds.h"

clang::tok::TokenKind shim(swift::tok kind) {
  switch (kind) {
  case swift::tok::kw_return:
	break;
  case swift::tok::kw_class:
    break;
  case swift::tok::kw_associatedtype:
    break;
  case swift::tok::kw_deinit:
    break;
  case swift::tok::kw_enum:
    break;
  case swift::tok::kw_extension:
    break;
  case swift::tok::kw_func:
    break;
  case swift::tok::kw_import:
    break;
  case swift::tok::kw_init:
    break;
  case swift::tok::kw_inout:
    break;
  case swift::tok::kw_let:
    break;
  case swift::tok::kw_operator:
    break;
  case swift::tok::kw_precedencegroup:
    break;
  case swift::tok::kw_protocol:
    break;
  case swift::tok::kw_struct:
    break;
  case swift::tok::kw_subscript:
    break;
  case swift::tok::kw_typealias:
    break;
  case swift::tok::kw_var:
    break;
  case swift::tok::kw_fileprivate:
    break;
  case swift::tok::kw_internal:
    break;
  case swift::tok::kw_private:
    break;
  case swift::tok::kw_public:
    break;
  case swift::tok::kw_static:
    break;
  case swift::tok::kw_defer:
    break;
  case swift::tok::kw_if:
    break;
  case swift::tok::kw_guard:
    break;
  case swift::tok::kw_do:
    break;
  case swift::tok::kw_repeat:
    break;
  case swift::tok::kw_else:
    break;
  case swift::tok::kw_for:
    break;
  case swift::tok::kw_in:
    break;
  case swift::tok::kw_while:
    break;
  case swift::tok::kw_break:
    break;
  case swift::tok::kw_continue:
    break;
  case swift::tok::kw_switch:
    break;
  case swift::tok::kw_case:
    break;
  case swift::tok::kw_default:
    break;
  case swift::tok::kw_where:
    break;
  case swift::tok::kw_fallthrough:
    break;
  case swift::tok::kw_catch:
    break;
  case swift::tok::kw_throw:
    break;
  case swift::tok::kw_as:
    break;
  case swift::tok::kw_Any:
    break;
  case swift::tok::kw_false:
    break;
  case swift::tok::kw_is:
    break;
  case swift::tok::kw_nil:
    break;
  case swift::tok::kw_rethrows:
    break;
  case swift::tok::kw_super:
    break;
  case swift::tok::kw_self:
    break;
  case swift::tok::kw_Self:
    break;
  case swift::tok::kw_true:
    break;
  case swift::tok::kw_try:
    break;
  case swift::tok::kw_throws:
    break;
  case swift::tok::kw___FILE__:
    break;
  case swift::tok::kw___COLUMN__:
    break;
  case swift::tok::kw___FUNCTION__:
    break;
  case swift::tok::kw___LINE__:
    break;
  case swift::tok::kw___DSO_HANDLE__:
    break;
  case swift::tok::kw__:
    break;
  case swift::tok::l_paren:
    break;
  case swift::tok::r_paren:
    break;
  case swift::tok::l_brace:
    break;
  case swift::tok::r_brace:
    break;
  case swift::tok::l_square:
    break;
  case swift::tok::r_square:
    break;
  case swift::tok::l_angle:
    break;
  case swift::tok::r_angle:
    break;
  case swift::tok::period:
    break;
  case swift::tok::period_prefix:
    break;
  case swift::tok::comma:
    break;
  case swift::tok::ellipsis:
    break;
  case swift::tok::colon:
    break;
  case swift::tok::semi:
    break;
  case swift::tok::equal:
    break;
  case swift::tok::at_sign:
    break;
  case swift::tok::pound:
    break;
  case swift::tok::amp_prefix:
    break;
  case swift::tok::arrow:
    break;
  case swift::tok::backtick:
    break;
  case swift::tok::backslash:
    break;
  case swift::tok::exclaim_postfix:
    break;
  case swift::tok::question_postfix:
    break;
  case swift::tok::question_infix:
    break;
  case swift::tok::string_quote:
    break;
  case swift::tok::single_quote:
    break;
  case swift::tok::multiline_string_quote:
    break;
  case swift::tok::pound_keyPath:
    break;
  case swift::tok::pound_line:
    break;
  case swift::tok::pound_selector:
    break;
  case swift::tok::pound_file:
    break;
  case swift::tok::pound_fileID:
    break;
  case swift::tok::pound_filePath:
    break;
  case swift::tok::pound_column:
    break;
  case swift::tok::pound_function:
    break;
  case swift::tok::pound_dsohandle:
    break;
  case swift::tok::pound_assert:
    break;
  case swift::tok::pound_sourceLocation:
    break;
  case swift::tok::pound_warning:
    break;
  case swift::tok::pound_error:
    break;
  case swift::tok::pound_if:
    break;
  case swift::tok::pound_else:
    break;
  case swift::tok::pound_elseif:
    break;
  case swift::tok::pound_endif:
    break;
  case swift::tok::pound_available:
    break;
  case swift::tok::pound_fileLiteral:
    break;
  case swift::tok::pound_imageLiteral:
    break;
  case swift::tok::pound_colorLiteral:
    break;
  case swift::tok::integer_literal:
    break;
  case swift::tok::floating_literal:
    break;
  case swift::tok::string_literal:
    break;
  case swift::tok::unknown:
    break;
  case swift::tok::identifier:
    break;
  case swift::tok::oper_binary_unspaced:
    break;
  case swift::tok::oper_binary_spaced:
    break;
  case swift::tok::oper_postfix:
    break;
  case swift::tok::oper_prefix:
    break;
  case swift::tok::dollarident:
    break;
  case swift::tok::contextual_keyword:
    break;
  case swift::tok::raw_string_delimiter:
    break;
  case swift::tok::string_segment:
    break;
  case swift::tok::string_interpolation_anchor:
    break;
  case swift::tok::kw_yield:
    break;
  case swift::tok::kw_undef:
    break;
  case swift::tok::kw_sil:
    break;
  case swift::tok::kw_sil_stage:
    break;
  case swift::tok::kw_sil_property:
    break;
  case swift::tok::kw_sil_vtable:
    break;
  case swift::tok::kw_sil_global:
    break;
  case swift::tok::kw_sil_witness_table:
    break;
  case swift::tok::kw_sil_default_witness_table:
    break;
  case swift::tok::kw_sil_differentiability_witness:
    break;
  case swift::tok::kw_sil_coverage_map:
    break;
  case swift::tok::kw_sil_scope:
    break;
  case swift::tok::sil_dollar:
    break;
  case swift::tok::sil_exclamation:
    break;
  case swift::tok::eof:
    break;
  case swift::tok::code_complete:
    break;
  case swift::tok::sil_local_name:
    break;
  case swift::tok::comment:
    break;
  case swift::tok::NUM_TOKENS:
    break;
    }
  return clang::tok::TokenKind::l_paren;
}

int main() {
  return 0;
}
