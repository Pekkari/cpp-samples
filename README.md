# README file for the C++ programming project: Dungeon-Crawler Game

This is a git repository for the programming project.
Its directory structure is as follows:

  * `plan/` -- Project plan, including a pdf file.

  * `doc/` -- The documentation sources related to the project, including the
    final version of the document **also as pdf file**.

  * `src/` -- Here are the C++ source files, with subfolders as needed.

  * `README.md` -- This file. It contains also build instructions.

You may also add other new directories as needed, for example
for testing tools.

# Build instructions

## Git submodules

The dependencies of the project (SFML and googletests) have been
added to the repository using submodules to let anybody share
the same versions during development. To get them over the git
submodules, be sure to clone the project using:
```
$ git clone --recursive git@courses-git.comnet.aalto.fi:CPP-F2020/cpu-emulator-2020-2.git
```
If you cloned it already, and you only want to bring the git
submodules, execute this:
```
$ git submodule update --init
```

## Cmake build

(Note: This is suitable for modern, updated systems, e.g., Ubuntu Focal Fossa
(20.04). For older systems such as Ubuntu Xenial Xerus (16.04) or Ubuntu Bionic
Beaver (18.04), gcc/g++ and cmake may need to be updated; see additional
instructions below.)

Install build dependencies of SFML, by executing:
```
$ sudo apt install cmake g++ libudev-dev libfreetype6-dev libopenal-dev \
libvorbis-dev libflac-dev libx11-dev libxrandr-dev mesa-common-dev
```
Create a build directory of your choice, for instance by executing:
```
$ mkdir build
$ cd build
```
Execute:
```
$ cmake ..
$ make
```
To build with test framework, run cmake with like following instead:
```
$ cmake .. -DBUILD_TESTING=true
```
To build  a debug version, run cmake with like following:
```
$ cmake .. -DCMAKE_BUILD_TYPE=Debug
```
This last will preserve the debug symbols to assist debugging through
gdb.

## Run the game

After a successful build, the game will be located under build/bin,
you can execute:
```
$ ./bin/dungeon-crawler
```
to start testing.

Note 1: We have successfully developed and tested on Ubuntu 20.04 (and
equivalent modern distros). For the older Ubuntu 16.04 and 18.04 (and
equivalent distros), the additional below steps are required to first update
the system. Successful tests have been performed on both Linux and WSL
(Windows Subsystem for Linux) on Windows 10 (requires also installing and
running the Xming X Server for Windows
(https://sourceforge.net/projects/xming/).

Note 2: On some systems,
```
$ export LIBGL_ALWAYS_INDIRECT=0
```
is needed to enable a trouble-free display.

Note 3: Displays with Nvidia drivers may require additional work.

================================================================================

# Older systems, Ubuntu 16.04 and 18.04: Required updates to gcc (gcc version
>= 9.1.x, preferred is >= 9.3.0) and cmake (cmake version >= 3.10.2, preferred
is >= 3.16.3)

First, one should ensure that the system is properly updated, using, e.g.:
```
$ sudo /bin/sh -c "apt update && apt dist-upgrade && apt autoremove && apt autoclean"
```

The default versions of compiler and cmake can
be checked using:
```
$ gcc --version
$ g++ --version # g++ will generally be an alias for gcc
$ cmake --version
```

## Update GNU compiler/standard libraries

Since the source uses C++17, gcc version needs to be >= 9
(https://gcc.gnu.org/projects/cxx-status.html#cxx17; the code also uses some C
standard library features such as std::filesystem first avaialable in 9.1.0).

gcc is typically installed as gcc-X, where X = 5 (16.04; typically version 5.3.0)
or 7 (18.04; typically version 7.5.0) while in Ubuntu 20.04 it is gcc-9
(typically version 9.3.0 or similar). Installing the later compiler versions
requires the following steps:

Only for Ubuntu Xenial Xerus (16.04):
```
$ sudo apt install g++ # since g++ may not be an alias in 16.04
```

For both Ubuntu Xenial Xerus (16.04) and Ubuntu Bionic Beaver (18.04):
```
$ sudo /bin/sh -c "apt update && apt dist-upgrade && apt autoremove && apt autoclean"
$ sudo apt install build-essential software-properties-common
$ sudo add-apt-repository ppa:ubuntu-toolchain-r/test
$ sudo apt update
$ sudo apt install gcc-9 # gcc will typically be updated to version >= 9.3.0
```
Next the default compiler version should be set (where 20 or 10 is the priority
and X = 5 or 7 for Ubuntu 16.04 and 18.04, respectively):
```
$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 20
$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 20
$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-X 10
$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-X 10
```
The default compiler version can be confirmed using:
```
$ sudo update-alternatives --config gcc
$ sudo update-alternatives --config g++
$ gcc --version
$ g++ --version
```
Update and clean up the system, using, e.g.:
```
$ sudo /bin/sh -c "apt update && apt dist-upgrade && apt autoremove && apt autoclean"
```

## Update cmake

cmake may also need to be updated, particularly in Ubuntu 16.04 (the typical
version is 3.5.1, while in 18.04 and 20.04 the typical versions are 3.10.2 and
3.16.3, respectively). The details are given at https://apt.kitware.com/.
To summarize, the below steps will be needed.

Install some necessary packages and obtain a copy of the signing key from the cmake developer:
```
$ wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null
$ sudo apt install apt-transport-https ca-certificates gnupg software-properties-common wget
```

Add the appropriate repository and update:

For Ubuntu Xenial Xerus (16.04):
```
$ sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ xenial main'
$ [optional: sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ xenial-rc main']
$ sudo apt update
$ sudo apt install cmake # cmake will typically be updated to version >= 3.19.1
```

For Ubuntu Bionic Beaver (18.04):
```
$ sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main'
$ [optional: sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic-rc main']
$ sudo apt update
$ sudo apt install cmake
```

Optionally, the default Ubuntu Focal Fossa (20.04) can be updated also:
```
$ sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ focal main'
$ [optional: sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ focal-rc main']
$ sudo apt update
$ sudo apt install cmake
```
and:
```
$ cmake --version
```

================================================================================

Possible additional steps needed on Ubuntu 16.04:
```
$ sudo apt remove libfreetype6-dev
$ sudo apt install libpng-dev
$ sudo apt install libfreetype6-dev
```

================================================================================

Finish by properly updating and cleaning up the system, using, e.g.:
```
$ sudo /bin/sh -c "apt update && apt dist-upgrade && apt autoremove && apt autoclean"
```

================================================================================
