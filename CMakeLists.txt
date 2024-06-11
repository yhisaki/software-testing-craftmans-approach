cmake_minimum_required(VERSION 3.0)
project(software-testing-craftmans-approach)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Triangle library
add_library(triangle src/triangle.cpp)
target_include_directories(triangle PUBLIC include)

# GoogleTest setup
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Test executable
add_executable(test_triangle test/test_triangle.cpp)
target_link_libraries(test_triangle ${GTEST_LIBRARIES} pthread triangle)

# Add test
add_test(NAME test_triangle COMMAND test_triangle)
