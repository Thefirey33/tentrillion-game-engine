![ten-trillion-logo](readme_sources/ten-trillion-logo.png)

# TEN-TRILLION GAME ENGINE

This game engine is a custom specialized game engine for extensive moddability and customizing of games.

The goal of the Ten-Trillion, is to provide all the optimizations that a developer manually does, directly bundled in,
but still able to control the code and rendering with function calls.

## Rendering Information

The Ten-Trillion will come equipped with SDL3 + Vulkan to allow for smooth and fast rendering of objects.

For backwards compatibility, OpenGL rendering will be supported.

## Requirements

This project uses SDL3, SDL Image, SDL Mixer for it's runtime. Along with:

- CMake 3.10.0
- C++ 17 (for Windows users, install Visual Studio 2017 or 2019 at minimum.)
- Git
- Vulkan and OpenGL SDK
- Qt 6
- SDL3, SDL3 Mixer, SDL3 Image

## Getting Started

Firstly, you need to register all the libraries / submodules in `libs/`. They are crucial for the runtime of the engine.

### Vulkan Installation

Vulkan is a needed dependency for the TenTrillion Game Engine, as the engine uses it to render it's graphics if your
system supports it. On Windows, please go to the [Vulkan Website](https://vulkan.lunarg.com/doc/sdk) and retrieve the
Vulkan SDK. Do not forget, ensure that the `VULKAN_SDK` path has been set correctly!

### OpenGL Installation

OpenGL is a needed dependency for the TenTrillion Game Engine. This is the fallback API that the TenTrillion will use if
Vulkan is not available.

### Qt Installation

You must also install Qt to compile the editor executable. For Windows users, you are recommended to use Qt's Installer
to install it to your system, [Check out this here.](https://doc.qt.io/qt-6/windows.html) Other desktop environments
can use their package managers.

Linux Users can read about it, right [here.](https://doc.qt.io/qt-6/linux.html)

#### Linux

SDL has dependencies for compiling that you need. If you are on Linux:

#### Ubuntu

```sh
sudo apt-get update
sudo apt-get install build-essential git make pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev libaudio-dev libfribidi-dev libjack-dev libsndio-dev libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev libthai-dev
```

#### Fedora

```sh
sudo dnf install gcc git-core make cmake  alsa-lib-devel fribidi-devel pulseaudio-libs-devel pipewire-devel libX11-devel libXext-devel libXrandr-devel libXcursor-devel libXfixes-devel libXi-devel libXScrnSaver-devel libXtst-devel dbus-devel ibus-devel systemd-devel mesa-libGL-devel libxkbcommon-devel mesa-libGLES-devel mesa-libEGL-devel vulkan-devel wayland-devel wayland-protocols-devel libdrm-devel mesa-libgbm-devel libusb1-devel libdecor-devel pipewire-jack-audio-connection-kit-devel libthai-devel
```

#### OpenSUSE TumbleWeed

```sh
sudo zypper in libunwind-devel libusb-1_0-devel Mesa-libGL-devel libxkbcommon-devel libdrm-devel  libgbm-devel pipewire-devel libpulse-devel sndio-devel Mesa-libEGL-devel alsa-devel xwayland-devel wayland-devel wayland-protocols-devel libthai-devel fribidi-devel
```

### Arch Linux

```sh
sudo pacman -S alsa-lib cmake hidapi ibus jack libdecor libthai fribidi libgl libpulse libusb libx11 libxcursor libxext libxfixes libxi libxinerama libxkbcommon libxrandr libxrender libxss libxtst mesa ninja pipewire sndio vulkan-driver vulkan-headers wayland wayland-protocols
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
> You will need an x64 Assembly Assembler to compile this project, along with Perl.

To build the project, do:

```sh
mkdir build
cd build # This will create a build directory for you to work with.
cmake ..
cmake --build .
```

## License

This project uses the MIT License.
