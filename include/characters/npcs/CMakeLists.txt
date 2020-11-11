cmake_minimum_required(VERSION 3.5)


add_library(npc SHARED npc.hpp ${dungeon-crawler_SOURCE_DIR}/characters/npcs/npc.cpp)
add_library(door SHARED door.hpp ${dungeon-crawler_SOURCE_DIR}/characters/npcs/door.cpp)
add_library(shopkeeper SHARED shopkeeper.hpp ${dungeon-crawler_SOURCE_DIR}/characters/npcs/shopkeeper.cpp)
add_library(wizard SHARED wizard.hpp ${dungeon-crawler_SOURCE_DIR}/characters/npcs/wizard.cpp)
add_library(chest SHARED chest.hpp ${dungeon-crawler_SOURCE_DIR}/characters/npcs/chest.cpp)

set_target_properties(npc PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(door PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(shopkeeper PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(wizard PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(chest PROPERTIES LINKER_LANGUAGE CXX)
