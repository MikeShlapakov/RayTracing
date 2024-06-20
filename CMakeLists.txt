# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# # Find the C++ compiler
# find_package(CMake REQUIRED)

# # Set the C++ compiler
# set(CMAKE_CXX_COMPILER "gcc" CACHE STRING "C++ Compiler")

# Project name
project(MyProgram VERSION 1.0 LANGUAGES CXX)

# # Set the C++ standard
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(rayTracing main.cpp)