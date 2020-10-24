```git checkout git@github.com:apple/llvm-project.git && cd llvm-project \
   &&  git checkout swift-5.3-RELEASE
```

Then download Swift 5.3 binary for your system.
And download its sources. We will use them directly, not the
packaged version.

./llvm/Support/Compiler.h:18:10: fatal error: llvm/Config/llvm-config.h: No such file or directory
 #include "llvm/Config/llvm-config.h"
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~

This is solved by configuring llvm-project. That is an easy task. Just
go there and run
```
   mkdir build && cd build && cmake ..
```
You will find the configured filed in the build directory. Copy them
where they need to be as per the references in top-level source code.