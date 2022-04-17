cmake_minimum_required(VERSION 3.22.3)

# set the project name
project(sieve)

# add the executable
add_executable(sieve sieve.cpp)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra -Werror -pedantic -g")
