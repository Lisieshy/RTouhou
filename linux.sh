#!/bin/bash

[ -d ./linux ] || mkdir linux
cd linux

conan install .. --build=missing -pr=Release

cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"

make -j18

# This line works to compile. CMake does not. What the fuck?
# g++ -g $(find RootFolderName -type f -iregex ".*\.cpp")