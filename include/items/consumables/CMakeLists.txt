cmake_minimum_required(VERSION 3.5)

add_library(consumable SHARED consumable.hpp ${dungeon-crawler_SOURCE_DIR}/items/consumables/consumable.cpp)
set_target_properties(consumable PROPERTIES LINKER_LANGUAGE CXX)
