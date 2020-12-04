cmake_minimum_required(VERSION 3.5)

add_executable(dungeon-crawler dungeon-crawler.cpp)
target_link_libraries(dungeon-crawler PRIVATE game chamber gameTile character player enemy npc goblin blackknight dragon finalboss chest door shopkeeper wizard item equipment consumable pthread display sfml-window sfml-graphics sfml-system)
target_include_directories(dungeon-crawler PUBLIC ${PROJECT_SOURCE_DIR}/include)
