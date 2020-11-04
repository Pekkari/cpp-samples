cmake_minimum_required(VERSION 3.5)

add_library(enemy SHARED enemy.hpp ${dungeon-crawler_SOURCE_DIR}/characters/enemies/enemy.cpp)
set_target_properties(enemy PROPERTIES LINKER_LANGUAGE CXX)
