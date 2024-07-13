cmake_minimum_required(VERSION 3.10)


project(ATMProject VERSION 1.0)


add_executable(ATMProject src/main.cpp)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(yaml-cpp REQUIRED)
target_link_libraries(ATMProject yaml-cpp)