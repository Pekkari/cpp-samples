cmake_minimum_required(VERSION 3.5)

add_library(npc SHARED npc.hpp ${dungeon-crawler_SOURCE_DIR}/characters/npcs/npc.cpp)
set_target_properties(npc PROPERTIES LINKER_LANGUAGE CXX)
