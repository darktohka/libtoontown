libdisney
===========
_libdisney_ is a project meant to modernize the libotp and libtoontown libraries created by Disney for their now closed MMORPG, Toontown Online.

Thanks to the project, it is now possible to use libotp and libtoontown in the newest Panda3D engine version, Panda3D 1.11.0.

It has been tested on both Python 2.7 and Python 3.8.

To switch the Panda3D SDK the project is built for, set the `PANDA_DIR` CMake variable.

To build for 32-bit Panda3D, use the `-A Win32` flag, whereas to build for 64-bit Panda3D, use `-A x64`.

**Major thanks to satire6 for releasing the [Anesidora](https://github.com/satire6/Anesidora) cache that made this project possible! Keep it up, and thank you so much!**

Usage
=====
Example build steps for 64-bit Panda3D installed at `C:/Panda3D-1.11.0-x64`:

```
mkdir build
cd build
cmake -G"Visual Studio 16 2019" -A x64 -DPANDA_DIR=C:/Panda3D-1.11.0-x64 ..
msbuild /p:Configuration=Release ALL_BUILD.vcxproj
```

Thanks for loblao's libpandadna project for the interrogate CMake project skeleton!
