cmake_minimum_required(VERSION 3.5)

add_library(libdog_class SHARED dog_class.hpp)
set_target_properties(libdog_class PROPERTIES LINKER_LANGUAGE CXX)
