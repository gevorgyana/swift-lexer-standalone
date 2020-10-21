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