cmake_minimum_required(VERSION 3.5)

add_library(equipment SHARED equipment.hpp ${dungeon-crawler_SOURCE_DIR}/items/equipments/equipment.cpp)
set_target_properties(equipment PROPERTIES LINKER_LANGUAGE CXX)
