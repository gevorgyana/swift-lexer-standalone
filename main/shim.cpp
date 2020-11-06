// convert swift tokens to clang tokens

#include "swift/Syntax/TokenSyntax.h"
#include "clang/Basic/TokenKinds.h"

void foo(clang::tok::TokenKind tok) {
  /*
  switch(tok) {
    case clang::tok::kw_return:
      break;
  }
  */

  /*
unknown,
eof,
eod,
code_completion,
comment,
identifier,
raw_identifier,
numeric_constant,
char_constant,
wide_char_constant,
utf8_char_constant,
utf16_char_constant,
utf32_char_constant,
string_literal,
wide_string_literal,
header_name,
utf8_string_literal,
utf16_string_literal,
utf32_string_literal,
l_square,
r_square,
l_paren,
r_paren,
l_brace,
r_brace,
period,
ellipsis,
amp,
ampamp,
ampequal,
star,
starequal,
plus,
plusplus,
plusequal,
minus,
arrow,
minusminus,
minusequal,
tilde,
exclaim,
exclaimequal,
slash,
slashequal,
percent,
percentequal,
less,
lessless,
lessequal,
lesslessequal,
spaceship,
greater,
greatergreater,
greaterequal,
greatergreaterequal,
caret,
caretequal,
pipe,
pipepipe,
pipeequal,
question,
colon,
semi,
equal,
equalequal,
comma,
hash,
hashhash,
hashat,
periodstar,
arrowstar,
coloncolon,
at,
lesslessless,
greatergreatergreater,
caretcaret,
kw_auto,
kw_break,
kw_case,
kw_char,
kw_const,
kw_continue,
kw_default,
kw_do,
kw_double,
kw_else,
kw_enum,
kw_extern,
kw_float,
kw_for,
kw_goto,
kw_if,
kw_inline,
kw_int,
kw_long,
kw_register,
kw_restrict,
kw_return,
kw_short,
kw_signed,
kw_sizeof,
kw_static,
kw_struct,
kw_switch,
kw_typedef,
kw_union,
kw_unsigned,
kw_void,
kw_volatile,
kw_while,
kw__Alignas,
kw__Alignof,
kw__Atomic,
kw__Bool,
kw__Complex,
kw__Generic,
kw__Imaginary,
kw__Noreturn,
kw__Static_assert,
kw__Thread_local,
kw___func__,
kw___objc_yes,
kw___objc_no,
kw___ptrauth,
kw_asm,
kw_bool,
kw_catch,
kw_class,
kw_const_cast,
kw_delete,
kw_dynamic_cast,
kw_explicit,
kw_export,
kw_false,
kw_friend,
kw_mutable,
kw_namespace,
kw_new,
kw_operator,
kw_private,
kw_protected,
kw_public,
kw_reinterpret_cast,
kw_static_cast,
kw_template,
kw_this,
kw_throw,
kw_true,
kw_try,
kw_typename,
kw_typeid,
kw_using,
kw_virtual,
kw_wchar_t,
kw_alignas,
kw_alignof,
kw_char16_t,
kw_char32_t,
kw_constexpr,
kw_decltype,
kw_noexcept,
kw_nullptr,
kw_static_assert,
kw_thread_local,
kw_concept,
kw_requires,
kw_co_await,
kw_co_return,
kw_co_yield,
kw_module,
kw_import,
kw_char8_t,
kw_consteval,
kw_constinit,
kw__Float16,
kw__Accum,
kw__Fract,
kw__Sat,
kw__Decimal32,
kw__Decimal64,
kw__Decimal128,
kw___null,
kw___alignof,
kw___attribute,
kw___builtin_choose_expr,
kw___builtin_offsetof,
kw___builtin_FILE,
kw___builtin_FUNCTION,
kw___builtin_LINE,
kw___builtin_COLUMN,
kw___builtin_types_compatible_p,
kw___builtin_va_arg,
kw___extension__,
kw___float128,
kw___imag,
kw___int128,
kw___label__,
kw___real,
kw___thread,
kw___FUNCTION__,
kw___PRETTY_FUNCTION__,
kw___auto_type,
kw_typeof,
kw___FUNCDNAME__,
kw___FUNCSIG__,
kw_L__FUNCTION__,
kw_L__FUNCSIG__,
kw___is_interface_class,
kw___is_sealed,
kw___is_destructible,
kw___is_trivially_destructible,
kw___is_nothrow_destructible,
kw___is_nothrow_assignable,
kw___is_constructible,
kw___is_nothrow_constructible,
kw___is_assignable,
kw___has_nothrow_move_assign,
kw___has_trivial_move_assign,
kw___has_trivial_move_constructor,
kw___has_nothrow_assign,
kw___has_nothrow_copy,
kw___has_nothrow_constructor,
kw___has_trivial_assign,
kw___has_trivial_copy,
kw___has_trivial_constructor,
kw___has_trivial_destructor,
kw___has_virtual_destructor,
kw___is_abstract,
kw___is_aggregate,
kw___is_base_of,
kw___is_class,
kw___is_convertible_to,
kw___is_empty,
kw___is_enum,
kw___is_final,
kw___is_literal,
kw___is_pod,
kw___is_polymorphic,
kw___is_standard_layout,
kw___is_trivial,
kw___is_trivially_assignable,
kw___is_trivially_constructible,
kw___is_trivially_copyable,
kw___is_union,
kw___has_unique_object_representations,
kw___underlying_type,
kw___reference_binds_to_temporary,
kw___is_lvalue_expr,
kw___is_rvalue_expr,
kw___is_arithmetic,
kw___is_floating_point,
kw___is_integral,
kw___is_complete_type,
kw___is_void,
kw___is_array,
kw___is_function,
kw___is_reference,
kw___is_lvalue_reference,
kw___is_rvalue_reference,
kw___is_fundamental,
kw___is_object,
kw___is_scalar,
kw___is_compound,
kw___is_pointer,
kw___is_member_object_pointer,
kw___is_member_function_pointer,
kw___is_member_pointer,
kw___is_const,
kw___is_volatile,
kw___is_signed,
kw___is_unsigned,
kw___is_same,
kw___is_convertible,
kw___array_rank,
kw___array_extent,
kw___private_extern__,
kw___module_private__,
kw___builtin_ptrauth_type_discriminator,
kw___declspec,
kw___cdecl,
kw___stdcall,
kw___fastcall,
kw___thiscall,
kw___regcall,
kw___vectorcall,
kw___forceinline,
kw___unaligned,
kw___super,
kw___global,
kw___local,
kw___constant,
kw___private,
kw___generic,
kw___kernel,
kw___read_only,
kw___write_only,
kw___read_write,
kw___builtin_astype,
kw_vec_step,
kw_image1d_t,
kw_image1d_array_t,
kw_image1d_buffer_t,
kw_image2d_t,
kw_image2d_array_t,
kw_image2d_depth_t,
kw_image2d_array_depth_t,
kw_image2d_msaa_t,
kw_image2d_array_msaa_t,
kw_image2d_msaa_depth_t,
kw_image2d_array_msaa_depth_t,
kw_image3d_t,
kw___builtin_omp_required_simd_align,
kw_pipe,
kw___pascal,
kw___vector,
kw___pixel,
kw___bool,
kw_half,
kw___bridge,
kw___bridge_transfer,
kw___bridge_retained,
kw___bridge_retain,
kw___covariant,
kw___contravariant,
kw___kindof,
kw__Nonnull,
kw__Nullable,
kw__Null_unspecified,
kw___ptr64,
kw___ptr32,
kw___sptr,
kw___uptr,
kw___w64,
kw___uuidof,
kw___try,
kw___finally,
kw___leave,
kw___int64,
kw___if_exists,
kw___if_not_exists,
kw___single_inheritance,
kw___multiple_inheritance,
kw___virtual_inheritance,
kw___interface,
kw___builtin_convertvector,
kw___builtin_bit_cast,
kw___builtin_available,
kw___unknown_anytype,
annot_cxxscope,
annot_typename,
annot_template_id,
annot_non_type,
annot_non_type_undeclared,
annot_non_type_dependent,
annot_primary_expr,
annot_decltype,
annot_pragma_unused,
annot_pragma_vis,
annot_pragma_pack,
annot_pragma_parser_crash,
annot_pragma_captured,
annot_pragma_dump,
annot_pragma_msstruct,
annot_pragma_align,
annot_pragma_weak,
annot_pragma_weakalias,
annot_pragma_redefine_extname,
annot_pragma_fp_contract,
annot_pragma_fenv_access,
annot_pragma_ms_pointers_to_members,
annot_pragma_ms_vtordisp,
annot_pragma_ms_pragma,
annot_pragma_opencl_extension,
annot_pragma_openmp,
annot_pragma_openmp_end,
annot_pragma_loop_hint,
annot_pragma_fp,
annot_pragma_attribute,
annot_module_include,
annot_module_begin,
annot_module_end,
annot_header_unit,

enum ObjCKeywordKind {
objc_not_keyword,
objc_class,
objc_compatibility_alias,
objc_defs,
objc_encode,
objc_end,
objc_implementation,
objc_interface,
objc_private,
objc_protected,
objc_protocol,
objc_public,
objc_selector,
objc_throw,
objc_try,
objc_catch,
objc_finally,
objc_synchronized,
objc_autoreleasepool,
objc_property,
objc_package,
objc_required,
objc_optional,
objc_synthesize,
objc_dynamic,
objc_import,
objc_available,
};


   */
  #include "clang/Basic/TokenKinds.def"
}

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
    return clang::tok::TokenKind::l_paren;
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
