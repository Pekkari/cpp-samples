cmake_minimum_required(VERSION 3.5)

add_library(libenemy SHARED enemy.hpp ${CMAKE_SOURCE_DIR}/characters/enemies/enemy.cpp)
set_target_properties(libenemy PROPERTIES LINKER_LANGUAGE CXX)
