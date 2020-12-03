cmake_minimum_required(VERSION 3.5)

add_executable(dungeon-crawler dungeon-crawler.cpp)
target_link_libraries(dungeon-crawler PRIVATE game chamber gameTile pthread display sfml-window sfml-graphics sfml-system character item equipment consumable player)
target_include_directories(dungeon-crawler PUBLIC ${PROJECT_SOURCE_DIR}/include)
