cmake_minimum_required(VERSION 3.5)

add_library(libitem SHARED item.hpp ${CMAKE_SOURCE_DIR}/items/item.cpp)
set_target_properties(libitem PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(consumables)
add_subdirectory(equipments)
