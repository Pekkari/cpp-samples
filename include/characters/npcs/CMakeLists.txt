cmake_minimum_required(VERSION 3.5)

add_library(libnpc SHARED npc.hpp ${CMAKE_SOURCE_DIR}/characters/npcs/npc.cpp)
set_target_properties(libnpc PROPERTIES LINKER_LANGUAGE CXX)
