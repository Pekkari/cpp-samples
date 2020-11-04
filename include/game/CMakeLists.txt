cmake_minimum_required(VERSION 3.5)

add_library(game SHARED game.hpp ${dungeon-crawler_SOURCE_DIR}/game/game.cpp)
set_target_properties(game PROPERTIES LINKER_LANGUAGE CXX)
