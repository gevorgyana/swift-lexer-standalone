// #include "clang/Basic/TokenKinds.h"
		      
#define OBJC_AT_KEYWORD(X) objc_##X,
		      #include "clang/Basic/TokenKinds.def"
		        NUM_OBJC_KEYWORDS
};

int main() {
  return 0;
}
