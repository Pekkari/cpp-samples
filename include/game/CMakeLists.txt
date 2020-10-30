cmake_minimum_required(VERSION 3.5)

add_library(libgame SHARED game.hpp ${CMAKE_SOURCE_DIR}/game/game.cpp)
set_target_properties(libgame PROPERTIES LINKER_LANGUAGE CXX)
