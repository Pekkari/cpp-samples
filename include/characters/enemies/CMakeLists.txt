cmake_minimum_required(VERSION 3.5)

add_library(enemy SHARED enemy.hpp ${dungeon-crawler_SOURCE_DIR}/characters/enemies/enemy.cpp)
add_library(dragon SHARED dragon.hpp ${dungeon-crawler_SOURCE_DIR}/characters/enemies/dragon.cpp)
add_library(finalboss SHARED finalboss.hpp ${dungeon-crawler_SOURCE_DIR}/characters/enemies/finalboss.cpp)
add_library(goblin SHARED goblin.hpp ${dungeon-crawler_SOURCE_DIR}/characters/enemies/goblin.cpp)
add_library(blackknight SHARED blackknight.hpp ${dungeon-crawler_SOURCE_DIR}/characters/enemies/blackknight.cpp)

set_target_properties(enemy PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(dragon PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(finalboss PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(goblin PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(blackknight PROPERTIES LINKER_LANGUAGE CXX)
