cmake_minimum_required(VERSION 3.5)

add_library(first SHARED first.hpp)
set_target_properties(first PROPERTIES LINKER_LANGUAGE CXX)
