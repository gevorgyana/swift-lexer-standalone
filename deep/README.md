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

Configure swift's update-checkout default config in python, change
its default-branch-scheme to release/5.3 because i am also working
with the binaries of this version and it simplifies debugging experience
as i am using lldb to look for backtraces to split the monolith into
smaller parts.
TODO explain how to do it.

After that, confirue swift:
```
./utils/update-checkout --clone
./utils/build-script --skip-build
```
The last command started the actual build, but it is not desired so
interrupt it when it tries to build the whole project.

TODO fix the last include flags in Makefile, better wrap this whole
thing as a script.x

Next, you need to do some .gyb-magic. Pick the Python tool and run
in in-tree - necessary .def files will appear.