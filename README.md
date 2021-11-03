# R-Touhou

Creating a R-Type like game in C++, with multiplayer Co-Op.

# Contributors

> **Aurélien Schulz** aka [@Lisieshy](https://github.com/Lisieshy)

> **Eliott Ferry** aka [@EliottFerry](https://github.com/EliottFerry)

> **Pierre Fricker** aka [@Exy-tek](https://github.com/Exy-tek)

> **Thomas Moreau** aka [@zoomzoomzen](https://github.com/zoomzoomzen)

> **Tom Wederich** aka [@TheGorb](https://github.com/TheGorb)

# How To Compile (IMPORTANT!)

First of all, you need [Conan](https://conan.io)

Then, you need [CMake >=3.17](https://cmake.org)

You also obviously need g++ to compile the cpp code.

Once you have everything installed, follow these steps :

1. First of all, you need to create a new conan profile

        $ conan profile new --detect

2. Then, edit the profile by opening the .conan/profiles folder in your home directory

        for linux:

        code ~/.conan/profiles/

        for windows:

        code C:/Users/<USERNAME>/.conan/profiles

3. Edit the default profile (The one you created earlier just now!)<br>
   and change the `compiler.cxx=libstdc++` to `compiler.cxx=libstdc++11`.<br>
   You can also change the compiler version here to match the one you use on your PC.<br>
   You can also change the `build_type` variable to change between Debug, Release, MinSizeRel and RelWithDebInfo. Be sure to match the one you'll use with CMake in the next steps.<br>
   Here is what a sample profile would look like if you used g++-10 and were on Linux.

        [settings]
        os=Linux
        os_build=Linux
        arch=x86_64
        arch_build=x86_64
        compiler=gcc
        compiler.version=10
        compiler.libcxx=libstdc++11
        build_type=Release
        [options]
        [build_requires]
        [env]

4. Now, go back to the project and create the build directory by running

        $ mkdir build
        $ cd build

5. Now run these commands to install the dependencies and configure the project

        $ conan install .. --build=missing
        /* Installing Dependencies, wait for a few minutes. */
        /* Make sure the DCMAKE_BUILD_TYPE is the same as the build_type in your conan profile. */
        $ cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
        $ make

6. For Windows, you should use cmake-gui and select Visual Studio 16 2019 for the target.

7. You're done! The compiled binaries will be located in ./build/bin/ !

# Documentation

The documentation is generated using Doxygen. It uses the doxygen-awesome theme.
It is available at [this address](https://portfolio.lisieshy.dev/RTouhou/).