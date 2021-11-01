#/bin/bash

[ -d ./windows ] || mkdir windows
cd windows

conan install .. --build=missing -pr=WindowsRelease

cmake.exe .. -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 16 2019"

MSBuild.exe rtouhou.sln /t:rtouhou_client /p:Configuration="Release" /p:Platform="x64" /p:BuildProjectReferences=false
