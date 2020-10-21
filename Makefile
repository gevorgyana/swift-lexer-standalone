# When compiling Lexer, add Confusables.cpp to the amalgamation
app: main.cpp Lexer.cpp Confusables.cpp
	g++ -g -fno-rtti main.cpp Lexer.cpp Confusables.cpp -iquote. -L./libraries/swift-5.3-RELEASE-ubuntu18.04/usr/lib/swift_static/linux -L./libraries/swift-5.3-RELEASE-ubuntu18.04/usr/lib/clang/10.0.0/lib/linux -L./libraries/swift-5.3-RELEASE-ubuntu18.04/usr/lib -lclang_rt.builtins-x86_64 -lBlocksRuntime -licui18nswift -lCFURLSessionInterface -licuucswift -lCFXMLInterface -lswiftCore -lCoreFoundation -lswift_Differentiation -ldispatch -lswiftDispatch -lDispatchStubs -lswiftGlibc -lFoundation -lswiftImageInspectionShared -lFoundationNetworking -lswiftSwiftOnoneSupport -lFoundationXML -luuid -licudataswift -lswiftDemangle -lsourcekitdInProc -o app

run: app
	LD_LIBRARY_PATH=$(CURDIR)/libraries/swift-5.3-RELEASE-ubuntu18.04/usr/lib/ ./app

lldb: app
	LD_LIBRARY_PATH=$(CURDIR)/libraries/swift-5.3-RELEASE-ubuntu18.04/usr/lib/ /usr/lib/llvm-11/bin/lldb app
