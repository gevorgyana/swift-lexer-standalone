This is a rewoked hack to make use of Swift Lexer from their
source code. In order for this to work, you must be running
Ubuntu (this limitation can be lifted soon), and you also
need to follow these steps:

- Download the Swift binaries (these are static libs that we
are going to link against) from here - my version is Ubuntu 18.04
https://swift.org/download/ , place them under binaries/

- Checkout apple/swift, then copy all of their inludes into current
working directory using `cp --parents -r`.
UPD: These files are lightweight so I have already included them
into this repository.

- Then run `sh compile.sh`

! Important note: to compile these headers, I had to run gyb (their
internal macro-processor) on some of the files. If you see erros
about some header missing, checkout swift source tree, then navigate
to utils/gyb.py and run this script on the files that match the beginning
of the names that are missing. For example, find A.h.gyb and run gyb.py
on it to obtain A.h, then copy A.h to where it needs to be. There may also
be .def files hidden behind .gyb extension. AFAIK, normally this is done
during the process of building swift, but it takes soooo long that my
machine was not able to do it even 12 hours into the compilation. It is
unappologetically long. The builds are incremental and the finer-grained
the tree is, the better performance of linking one or two components from
scratch is. But the initial build still would take me more than 12 hours,
which is just insane!

This project uses clang dependencies. You have to compile clang-format
separately on your local machine first. Some files need to be configured
on your machine, like

`calng/Basic/Version.inc`,
`clang/Basic/DiagnosticCommonKinds.inc`.

Maybe I missed some headers, but anyway, you should (currently) get
the files when building clang before proceeding with this software.
I have included my files in git, but probably this hardcodes some of
the logic that clang tries to lift.

16:21, 21.10
Need to include the binary dependencies of clang-format. It is not a
bad problem to build that, it only takes ~1hr (not 10hrs like Swift!).
Will not inlcude them to VCS, libraries/ is gitignored.

16:28, 21.10 Maybe it is better to rely on packages??

23:50, 21.10 Solved: just need to set LD_LIBRARY_PATH on linux, and a
similar environment var on OSX. Windows should be easy to support too.

The next step is to conver clang::SourceManager to swift::SourceManger,
seems like an easy task because swift was clearly copied from clang, and
there is a whole ClangImporter module in swift (maybe it can help?)

No. SourceManager in swift is different from SourceManager in clang.
SourceManager in clang is what we use when working with clang-format,
SourceManager in Swift should be satisfied to feed it to the code that
must perform tokenization. Maybe it is more reasonable to split
getting Tokens from the rest of the code - and in that part of the
program, interact with code as Swift does. Then obtian a series of
Tokens, adapt them to clang representation and here we go - we can format
them now.

NOTE: -- if checking these out, make sure you check out correct tags!!!
      -- not master/dev/etc. branch, but tags!

- git@github.com:apple/llvm-project.git
- git@github.com:apple/swift.git


- On fresh ubuntu, install `libicu-dev libicu66` -- intenrational support for unicode
https://packages.ubuntu.com/focal/libicu-dev
everything else is easily installed. this was tested with fresh focal ubuntu.
- `uuid-dev`
- Install what it asks to install - lld, sth. else that is easily inferred.
- Install `python-is-python3` and `python-all`. The first binds `python` to
`python3` and the second installs the maximum python2 that is availabe.