cmake_minimum_required(VERSION 3.5)

add_executable(dungeon-crawler dungeon-crawler.cpp)
target_link_libraries(dungeon-crawler PRIVATE pthread stdc++fs game chamber gameTile texture_loader display character player enemy npc goblin blackknight dragon finalboss chest door shopkeeper wizard item equipment consumable sfml-window sfml-graphics sfml-system)
target_include_directories(dungeon-crawler PUBLIC ${PROJECT_SOURCE_DIR}/include)
