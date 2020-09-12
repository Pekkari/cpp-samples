cmake_minimum_required(VERSION 3.5)

add_library(libvector SHARED vector.hpp)
set_target_properties(libvector PROPERTIES LINKER_LANGUAGE CXX)
