# Sample README file for C++ programming project

This is an initial git repository for your programming project.
It contains an initial directory structure that we wish you could
use as follows:

  * `plan/` -- Your project plan should be put here. You may use different sources,
    but we hope to get the plan **also as a pdf file**.

  * `doc/` -- The documentation sources related to your project should be put here.
    You may use different tools for documentation (e.g. latex),
    but we hope to get the final version of the document
    **also as pdf file**.

  * `src/` -- Here are the C++ source files. You can have subfolders as needed.

  * `README.md` -- This file. You should modify it to represent
    your project.

You may also add other new directories as needed, for example
for testing tools.

# Build instructions

## Git submodules

The dependencies of the project(SFML, and googletests) have been
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

The following build instructions have been tested using Ubuntu
Focal(20.04). Instructions may vary if you use a different serie
of Ubuntu, or a different debian derivative.

Install build dependencies of SFML, by executing:
```
sudo apt install cmake g++ libudev-dev libfreetype6-dev libopenal-dev libvorbis-dev libflac-dev libx11-dev libxrandr-dev mesa-common-dev
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
./bin/dungeon-crawler
```
To start testing.
