cmake_minimum_required(VERSION 3.5)

add_executable(first_touch main.cpp first.cpp)
target_link_libraries(first_touch PRIVATE first)
target_include_directories(first_touch PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_custom_target(run-first_touch ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/first_touch)
