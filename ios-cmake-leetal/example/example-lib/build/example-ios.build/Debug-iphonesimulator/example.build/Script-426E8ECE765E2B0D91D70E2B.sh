#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  /opt/homebrew/Cellar/cmake/3.23.1_1/bin/cmake -E cmake_symlink_library /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/Debug${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/Debug${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/Debug${EFFECTIVE_PLATFORM_NAME}/libexample.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  /opt/homebrew/Cellar/cmake/3.23.1_1/bin/cmake -E cmake_symlink_library /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/Release${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/Release${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/Release${EFFECTIVE_PLATFORM_NAME}/libexample.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  /opt/homebrew/Cellar/cmake/3.23.1_1/bin/cmake -E cmake_symlink_library /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libexample.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  /opt/homebrew/Cellar/cmake/3.23.1_1/bin/cmake -E cmake_symlink_library /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libexample.dylib /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libexample.dylib
fi

