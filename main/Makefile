# Do not forget to set command-line arguments

all: lexer.cpp Lexer.cpp Confusables.cpp shim.cpp
	clang++ -g -fno-rtti lexer.cpp Lexer.cpp Confusables.cpp shim.cpp -L$(addprefix $(SWIFT_BINARIES), /swift_static/linux) -L$(addprefix $(SWIFT_BINARIES), /clang/10.0.0/lib/linux) -L$(SWIFT_BINARIES) -lclang_rt.builtins-x86_64 -lBlocksRuntime -licui18nswift -lCFURLSessionInterface -licuucswift -lCFXMLInterface -lswiftCore -lCoreFoundation -lswift_Differentiation -ldispatch -lswiftDispatch -lDispatchStubs -lswiftGlibc -lFoundation -lswiftImageInspectionShared -lFoundationNetworking -lswiftSwiftOnoneSupport -lFoundationXML -luuid -licudataswift -lswiftDemangle -lsourcekitdInProc -o lexer -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/llvm-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/swift-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/clang/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /swift/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/llvm/include)
	LD_LIBRARY_PATH=$(SWIFT_BINARIES) ./lexer main.swift
	# rm lexer

lldb: lexer.cpp Lexer.cpp Confusables.cpp shim.cpp
	clang++ -g -fno-rtti lexer.cpp Lexer.cpp Confusables.cpp shim.cpp -L$(addprefix $(SWIFT_BINARIES), /swift_static/linux) -L$(addprefix $(SWIFT_BINARIES), /clang/10.0.0/lib/linux) -L$(SWIFT_BINARIES) -lclang_rt.builtins-x86_64 -lBlocksRuntime -licui18nswift -lCFURLSessionInterface -licuucswift -lCFXMLInterface -lswiftCore -lCoreFoundation -lswift_Differentiation -ldispatch -lswiftDispatch -lDispatchStubs -lswiftGlibc -lFoundation -lswiftImageInspectionShared -lFoundationNetworking -lswiftSwiftOnoneSupport -lFoundationXML -luuid -licudataswift -lswiftDemangle -lsourcekitdInProc -o lexer -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/llvm-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/swift-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/clang/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /swift/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/llvm/include)
# ending with usr/lib
	LD_LIBRARY_PATH=$(SWIFT_BINARIES) /usr/lib/llvm-11/bin/lldb ./lexer main.swift
	rm lexer

preproc: TokenKinds.h
	clang++ -E TokenKinds.h -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/llvm-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/swift-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/clang/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /swift/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/llvm/include)

generate_clang_tokens: shim.cpp
	clang++ shim.cpp -o generate_clang_tokens -L$(addprefix $(SWIFT_BINARIES), /swift_static/linux) -L$(addprefix $(SWIFT_BINARIES), /clang/10.0.0/lib/linux) -L$(SWIFT_BINARIES) -lclang_rt.builtins-x86_64 -lBlocksRuntime -licui18nswift -lCFURLSessionInterface -licuucswift -lCFXMLInterface -lswiftCore -lCoreFoundation -lswift_Differentiation -ldispatch -lswiftDispatch -lDispatchStubs -lswiftGlibc -lFoundation -lswiftImageInspectionShared -lFoundationNetworking -lswiftSwiftOnoneSupport -lFoundationXML -luuid -licudataswift -lswiftDemangle -lsourcekitdInProc -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/llvm-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/swift-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/clang/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /swift/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/llvm/include)
# ending with usr/lib
	LD_LIBRARY_PATH=$(SWIFT_BINARIES) ./generate_clang_tokens
	rm generate_clang_tokens

generate_clang_tokens_prep: shim.cpp
	clang++ -E shim.cpp -L$(addprefix $(SWIFT_BINARIES), /swift_static/linux) -L$(addprefix $(SWIFT_BINARIES), /clang/10.0.0/lib/linux) -L$(SWIFT_BINARIES) -lclang_rt.builtins-x86_64 -lBlocksRuntime -licui18nswift -lCFURLSessionInterface -licuucswift -lCFXMLInterface -lswiftCore -lCoreFoundation -lswift_Differentiation -ldispatch -lswiftDispatch -lDispatchStubs -lswiftGlibc -lFoundation -lswiftImageInspectionShared -lFoundationNetworking -lswiftSwiftOnoneSupport -lFoundationXML -luuid -licudataswift -lswiftDemangle -lsourcekitdInProc -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/llvm-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /build/Ninja-DebugAssert/swift-linux-x86_64/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/clang/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /swift/include) -I$(addprefix $(SWIFT_CONFIGURED_SOURCES), /llvm-project/llvm/include)
# ending with usr/lib

em_clean:
	rm *~
