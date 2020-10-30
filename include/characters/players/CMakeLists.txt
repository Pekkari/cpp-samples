cmake_minimum_required(VERSION 3.5)

add_library(libplayer SHARED player.hpp ${CMAKE_SOURCE_DIR}/characters/players/player.hpp)
set_target_properties(libplayer PROPERTIES LINKER_LANGUAGE CXX)
