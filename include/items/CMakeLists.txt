cmake_minimum_required(VERSION 3.5)

add_library(item SHARED item.hpp ${dungeon-crawler_SOURCE_DIR}/items/item.cpp)
set_target_properties(item PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(consumables)
add_subdirectory(equipments)
