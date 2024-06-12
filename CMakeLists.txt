cmake_minimum_required(VERSION 3.0)
project(software-testing-craftmans-approach)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Triangle library
add_library(triangle src/triangle.cpp)
target_include_directories(triangle PUBLIC include)

# Next Date library
add_library(next_date src/next_date.cpp)
target_include_directories(next_date PUBLIC include)

# GoogleTest setup
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test executable for triangle
add_executable(test_triangle test/test_triangle.cpp)
target_link_libraries(test_triangle ${GTEST_LIBRARIES} pthread triangle)

# Add test
add_test(NAME test_triangle COMMAND test_triangle)

# Test executable for next_date
add_executable(test_next_date test/test_next_date.cpp)
target_link_libraries(test_next_date ${GTEST_LIBRARIES} pthread next_date)

# Add test
add_test(NAME test_next_date COMMAND test_next_date)
