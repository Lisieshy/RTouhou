#!/bin/bash

[ -d ./linux ] || mkdir linux
cd linux

conan install .. --build=missing -pr=default

cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"

make -j18