# To Generate CMAKE files on 'build' folder => cmake -H. -Bbuild
# To Use the 'build' folder to build        => cmake --build build

cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "")
project(turnBasedRPG)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(TESTS_DIR ${PROJECT_SOURCE_DIR}/tests)
include_directories("${PROJECT_SOURCE_DIR}")
SET(GCC_COVERAGE_LINK_FLAGS "-v")

# unit testing
add_executable(stats_test ${TESTS_DIR}/Stats.cpp)
add_executable(math_utilities ${TESTS_DIR}/MathUtilities.cpp)

# ./bin/size && ./bin/twopkmn