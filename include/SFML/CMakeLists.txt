cmake_minimum_required(VERSION 3.5)

add_library(input SHARED input.hpp ${dungeon-crawler_SOURCE_DIR}/SFML/input.cpp)
set_target_properties(input PROPERTIES LINKER_LANGUAGE CXX)
add_library(display SHARED display.hpp ${dungeon-crawler_SOURCE_DIR}/SFML/display.cpp)
target_link_libraries(display PRIVATE input)
set_target_properties(display PROPERTIES LINKER_LANGUAGE CXX)
