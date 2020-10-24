 #include "swift/Frontend/Frontend.h"

// Use Swift Lexer

int main() {












  // just get a swift::CompilerInstance and call its method
  // CompilerInstance::setUpASTContextIfNeeded(), but in simplified
  // form - you will have to remove some of it
  // This is the highest level I should start working from.

  // SetUpASTContextIfNeede
  // CompilerInstance::setUpASTContextIfNeeded()

  // needs swift::SourceManager

  // swift::ClangImporter::create() creates everything!
  // (needs swift::ASTContext)
  //
  /*
      *** there is some stuff before that
      // Set up the file manager.
      {
      llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> VFS =
      clang::createVFSFromCompilerInvocation(instance.getInvocation(),
      instance.getDiagnostics(),
      ctx.SourceMgr.getFileSystem(

      ));
      instance.createFileManager(std::move(VFS));

      }
   */

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
