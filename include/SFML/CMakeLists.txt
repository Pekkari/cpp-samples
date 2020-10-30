cmake_minimum_required(VERSION 3.5)

add_library(libinput SHARED input.hpp ${CMAKE_SOURCE_DIR}/SFML/input.cpp)
set_target_properties(libinput PROPERTIES LINKER_LANGUAGE CXX)
