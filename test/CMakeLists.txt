cmake_minimum_required(VERSION 3.16)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp)
target_include_directories(test PUBLIC ../ ${PROJECT_SOURCE_DIR})
target_link_libraries(test PUBLIC CDiscord)