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
