#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  make -f /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  make -f /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  make -f /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build
  make -f /Users/raoul/dev/imnu-universe/3rd-party-tools/ios-cmake-leetal/example/example-lib/build/CMakeScripts/ReRunCMake.make
fi

