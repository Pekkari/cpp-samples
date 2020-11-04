cmake_minimum_required(VERSION 3.5)

add_library(player SHARED player.hpp ${dungeon-crawler_SOURCE_DIR}/characters/players/player.cpp)
set_target_properties(player PROPERTIES LINKER_LANGUAGE CXX)
