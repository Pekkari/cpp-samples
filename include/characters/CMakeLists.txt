cmake_minimum_required(VERSION 3.5)

add_library(libcharacter SHARED character.hpp ${CMAKE_SOURCE_DIR}/characters/character.cpp)
set_target_properties(libcharacter PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(SFML)
add_subdirectory(characters)
add_subdirectory(game)
add_subdirectory(items)
