cmake_minimum_required(VERSION 3.5)

add_library(character SHARED character.hpp ${dungeon-crawler_SOURCE_DIR}/characters/character.cpp)
set_target_properties(character PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(enemies)
add_subdirectory(npcs)
add_subdirectory(players)
