cmake_minimum_required(VERSION 3.5)

add_executable(bank_account main.cpp bank_account.cpp)
target_link_libraries(bank_account PRIVATE libbank_account)
target_include_directories(bank_account PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_custom_target(run-bank_account ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bank_account)
