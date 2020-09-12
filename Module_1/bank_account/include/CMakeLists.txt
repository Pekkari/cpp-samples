cmake_minimum_required(VERSION 3.5)

add_library(libbank_account SHARED bank_account.hpp)
set_target_properties(libbank_account PROPERTIES LINKER_LANGUAGE CXX)
