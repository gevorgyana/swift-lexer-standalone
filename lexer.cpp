// Use Swift Lexer

int main() {
  // ClangImporter::create() creates everything!
  // clang::CompielerInstance::createFileManager(llvm::vfs::FileSystem)
  // llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem>
  // FileManager
  // SourceManager clang::namespace  | clang namespace
  // ---------------------------------
  //                                 | it is a all swift:: namespace
  //
  // ... easier to creaet ASTContext |
  //                                  for some reason,
  //                                  clang::ASTContext is also
  //                                  constructed by ClangImporter.
  //
  // SwiftIdentifier | ASTContext
  // ModuleDecl
  // SourceFile
  // Lexer
  return 0;
}
