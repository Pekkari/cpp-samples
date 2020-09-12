cmake_minimum_required(VERSION 3.5)

add_executable(vector_strings main.cpp vector_strings.cpp)
target_link_libraries(vector_strings PRIVATE libvector_strings)
target_include_directories(vector_strings PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_custom_target(run-vector_strings ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/vector_strings)
