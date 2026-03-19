# TEN-TRILLION GAME ENGINE

This game engine is a custom specialized game engine for extensive moddability and customizing of games.

The goal of the Ten-Trillion, is to provide all the optimizations that a developer manually does, directly bundled in, but still able to control the code and rendering with function calls.

## Rendering Information

The Ten-Trillion will come equipped with SDL3 + Vulkan to allow for smooth and fast rendering of objects.

For backwards compatibility, OpenGL rendering will be supported.

## Requirements

This project uses SDL3, SDL Image, SDL Mixer for it's runtime. Along with:

- CMake 3.10.0
- C++ 17 (for Windows users, install Visual Studio 2017 or 2019 at minimum.)
- Git

## Getting Started

Firstly, you need to register all the libraries / submodules in `libs/`. They are crucial for the runtime of the engine.

Do:

```sh
git submodule update --init
```

To register the required libraries and clone them to the directory.

## Building & Running

You can use the VSCode CMake Tools Extension, to get you quickly running and building the application without hassle.

To build the project, do:

```sh
mkdir build
cd build # This will create a build directory for you to work with.
cmake ..
cmake --build .
```
