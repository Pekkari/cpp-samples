cmake_minimum_required(VERSION 3.5)

add_library(librectangle SHARED rectangle.hpp)
set_target_properties(librectangle PROPERTIES LINKER_LANGUAGE CXX)
