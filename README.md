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

SDL has dependencies for compiling that you need. If you are on Linux (Ubuntu/Debian), use this:

```sh
sudo apt-get update
sudo apt-get install build-essential git make pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev libaudio-dev libfribidi-dev libjack-dev libsndio-dev libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev libthai-dev
```

Do:

```sh
git submodule update --init --recursive
```

To register the required libraries and clone them to the directory.

## Building & Running

You can use the VSCode CMake Tools Extension, to get you quickly running and building the application without hassle.

> ### **ATTENTION - WINDOWS USERS, IMPORTANT!**
>
> You will need an Assembler to compile this project. A recomemnded one is NASM or Microsoft's Macro Assembler. (MASM). Otherwise, the building does not work!

To build the project, do:

```sh
mkdir build
cd build # This will create a build directory for you to work with.
cmake ..
cmake --build .
```
