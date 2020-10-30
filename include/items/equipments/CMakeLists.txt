cmake_minimum_required(VERSION 3.5)

add_library(libequipment SHARED equipment.hpp ${CMAKE_SOURCE_DIR}/items/equipments/equipment.cpp)
set_target_properties(libequipment PROPERTIES LINKER_LANGUAGE CXX)
