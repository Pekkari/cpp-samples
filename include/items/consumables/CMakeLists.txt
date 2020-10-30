cmake_minimum_required(VERSION 3.5)

add_library(libconsumable SHARED consumable.hpp ${CMAKE_SOURCE_DIR}/items/consumables/consumable.cpp)
set_target_properties(libconsumable PROPERTIES LINKER_LANGUAGE CXX)
