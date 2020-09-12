cmake_minimum_required(VERSION 3.5)

add_library(libperson SHARED person.hpp)
set_target_properties(libperson PROPERTIES LINKER_LANGUAGE CXX)
