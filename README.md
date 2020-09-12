libdisney
===========
_libdisney_ is a project meant to modernize the libotp and libtoontown libraries created by Disney for their now closed MMORPG, Toontown Online.

Thanks to the project, it is now possible to use libotp and libtoontown in the newest Panda3D engine version, Panda3D 1.11.0.

Currently, it supports Python 2.7, but Python 3 support will be added soon.

**Major thanks to satire6 for releasing the [https://github.com/satire6/Anesidora](Anesidora) cache that made this project possible! Keep it up, and thank you so much!**

Usage
=====
```
mkdir build
cd build
cmake -G"Visual Studio 16 2019" -A Win32 ..
msbuild /p:Configuration=Release ALL_BUILD.vcxproj
```

Thanks for loblao's libpandadna project for the interrogate CMake project skeleton!
