# i used AI to write CMakeLists.txt! I'm very sorry, but I don't know, how to write CMake :(

cmake_minimum_required(VERSION 3.10)

project(Fractions VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/fractions.cpp
    src/arithmetic_operations.cpp
    src/comparison.cpp
    src/utils.cpp
)

add_library(fractions STATIC ${SOURCES})

target_include_directories(fractions PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_include_directories(fractions PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Tests soon!!!
# add_executable(fractions_test main.cpp)
# target_link_libraries(fractions_test PRIVATE fractions)