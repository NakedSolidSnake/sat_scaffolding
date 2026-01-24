cmake_minimum_required (VERSION 3.7.0)

project (SAT_SCAFFOLDING)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -Werror -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)

add_subdirectory (modes)
add_subdirectory (src)