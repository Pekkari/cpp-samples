cmake_minimum_required(VERSION 3.5)

add_library(libvector_strings SHARED vector_strings.hpp)
set_target_properties(libvector_strings PROPERTIES LINKER_LANGUAGE CXX)
