cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(ME492Fall2024)

set(CMAKE_BUILD_TYPE "Release")
#set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -pedantic -std=c++11")
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -pedantic -std=gnu11")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wconversion -pedantic -std=c++11 -g -O0")
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -Wconversion -pedantic -std=gnu11 -g -O0")

list(APPEND CMAKE_PREFIX_PATH "$HOM/opt/homebrew/opt/libomp/")
find_package(OpenMP REQUIRED)
message (STATUS "OpenMP_VERSION: ${OpenMP_VERSION}")
message(STATUS "OpenMP_INCLUDE_DIRS = ${OpenMP_INCLUDE_DIRS}")
message(STATUS "OpenMP_LIBRARIES = ${OpenMP_LIBRARIES}")

find_package(Boost 1.66 REQUIRED COMPONENTS filesystem log system thread filesystem date_time program_options unit_test_framework regex program_options)
message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")

message(STATUS "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG = ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_C_FLAGS_DEBUG = ${CMAKE_C_FLAGS_DEBUG}")

enable_testing()
add_subdirectory(practice_01)
add_subdirectory(practice_02)
add_subdirectory(homework4)
