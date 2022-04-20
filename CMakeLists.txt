cmake_minimum_required(VERSION 3.22.3)

# set the project name
project(sieve)

# add the executable
add_executable(sieve sieve.cpp main.cpp)
add_executable(test sieve.cpp test.cpp)

include_directories(/usr/include/CppUTest /usr/include/CppUTestExt)

# CppUTest
find_package(CppUTest REQUIRED)
target_link_libraries(test PRIVATE
    CppUTest
    CppUTestExt)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra -Werror -pedantic -g")
