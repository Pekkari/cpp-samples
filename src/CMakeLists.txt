cmake_minimum_required(VERSION 3.5)

add_executable(dungeon-crawler dungeon-crawler.cpp)
target_link_libraries(dungeon-crawler PRIVATE pthread display sfml-window sfml-graphics sfml-system)
target_include_directories(dungeon-crawler PUBLIC ${PROJECT_SOURCE_DIR}/include)
