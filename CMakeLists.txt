cmake_minimum_required(VERSION 3.16)

set(CMAKE_COMPILER_IS_GNUCC )
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED_ON)

project(ProjectDAC)

message(STATUS "CC set to: $ENV{CC}")
message(STATUS "CXX set to:$ENV{CXX}")




set(CPU_FLAGS -mcpu=cortex-m4)

add_subdirectory(Common)
add_subdirectory(Testing)