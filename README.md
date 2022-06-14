# Simple example
Simple example to reproduce issue https://github.com/msgpack/msgpack-c/issues/1025

# Steps
1. Clone this project and `cd` into it.
2. Make sure that `liboost` and its dependencies are not installed on you system. For Debian-based OS:
    ```bash
    sudo apt remove libboost-all-dev
    sudo apt autoremove
    ```
3. Clean the build directoy if you built once with `boost` installed (linking may persist)
    ```bash
    rm -rf ./build
    ```
4. Run `cmake` with `-DMSGPACK_USE_BOOST=OFF`. This will use `FetchContent` to pull `msgpack-c` (see `cmake/FetchContent_Declare_msgpack.cmake`). You can specify your generator with `-G` (e.g. `-G Ninja`).
    ```bash
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DMSGPACK_USE_BOOST=OFF
    ```
5. Build
    ```bash
    cmake --build build
    ```
    You should see an output similar to this:
    ```bash
    [ 50%] Building CXX object CMakeFiles/example.dir/main.cpp.o
    In file included from /msgpack_example/main.cpp:3:
    In file included from /msgpack_example/build/_deps/msgpackc-src/include/msgpack.hpp:10:
    In file included from /msgpack_example/build/_deps/msgpackc-src/include/msgpack/object.hpp:13:
    In file included from /msgpack_example/build/_deps/msgpackc-src/include/msgpack/object_decl.hpp:14:
    In file included from /msgpack_example/build/_deps/msgpackc-src/include/msgpack/v1/object_decl.hpp:14:
    In file included from /msgpack_example/build/_deps/msgpackc-src/include/msgpack/pack.hpp:13:
    In file included from /msgpack_example/build/_deps/msgpackc-src/include/msgpack/pack_decl.hpp:13:
    In file included from /msgpack_example/build/_deps/msgpackc-src/include/msgpack/v1/pack_decl.hpp:15:
    /msgpack_example/build/_deps/msgpackc-src/include/msgpack/sysdep.hpp:102:10: fatal error: 'boost/predef/other/endian.h' file not found
    #include <boost/predef/other/endian.h>
            ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    1 error generated.
    gmake[2]: *** [CMakeFiles/example.dir/build.make:76: CMakeFiles/example.dir/main.cpp.o] Error 1
    gmake[1]: *** [CMakeFiles/Makefile2:100: CMakeFiles/example.dir/all] Error 2
    gmake: *** [Makefile:136: all] Error 2
    ```
