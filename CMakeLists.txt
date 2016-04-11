cmake_minimum_required(VERSION 3.3)
project(sorter)

#include_directories("/usr/include/python3.5m/")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=c11 -g -fPIC")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/andreas/workspace/sorter/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "/home/andreas/workspace/sorter/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "/home/andreas/workspace/sorter/lib")

set(SOURCE_FILES src/sorter.c src/sorter.h)

#add_library(sharedcalign SHARED ${SOURCE_FILES})
#add_library(staticcalign STATIC ${SOURCE_FILES})
add_executable(sorter ${SOURCE_FILES})

