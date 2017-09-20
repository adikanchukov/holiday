# Holiday
Console application for obtaining information about upcoming holidays.

![alt tag](http://i.imgur.com/7dOJPJS.jpg?1)


## Build Requires
* C++ 11-compatible compiler
* CMake >= 2.8.8
* Qt 5 (*tested with Qt 5.5.1*)

## Building
1. Set your Qt 5 installation path in *CMakeLists.txt* (instructions inside).
2. Run *cmake && make*.
3. Place */packages* directory near the executable file or set the path manually with the *-p* or *--packageDir* option.

##Installation
The default installation directory is */usr/local/*.

You can specify your installation path by running *cmake -DCMAKE_INSTALL_PREFIX=...*.

Then *sudo make install*.

## Usage
Just run it!

Use *-h* or *--help* option for more details.

## Packages
You can create your own holiday packages.

Some examples in */packages* directory.

See *README* at the same place for more details.
