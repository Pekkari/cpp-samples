cmake_minimum_required(VERSION 3.5)

add_executable(vector main.cpp vector.cpp)
target_link_libraries(vector PRIVATE libvector)
target_include_directories(vector PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_custom_target(run-vector ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/vector)
