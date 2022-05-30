to make dylib, follow leetal readme and run

cd -> ios-cmake-leetal/example/example-lib/build
rm -rf *
cmake .. -G Xcode -DCMAKE_TOOLCHAIN_FILE=../../ios.toolchain.cmake -DPLATFORM=SIMULATORARM64
and
cmake --build . --config Debug

======================================================

from: https://www.youtube.com/watch?v=9Ynv8X9KcHc

default access modifier in swift is internal, means not viewable outside of lib. Use public

Swift source files get auto exposed (GameCharacter.swift).

Objective-C sources (Level.h/.m) have to be declared in alabank_project.h.

You get the error:

Include of non-modular header inside framework module 'alabang_project': '/Users/raoul/dev/alabang_project/alabang_project/Level.h'

if the file target membership is set to "Project" as default, change it to "Public".

To use Swift code in Objective-C, import a magical header file: <project-name>/<project-name>-Swift.h> into the implementation .m file

That file name is defined in: alabang_project, select target alabang_project, build settings, then under: Swift Compiler General: Objective-C Generated Interface Header Name.

And forward declare the Class in the, this time, .h file the classes used, here:

    @class GameCharacter;

Also, the swift class fields, to be usable in Objective-C, have to be prepended (annotated?) with @objc:

        @objc public let name: String;
