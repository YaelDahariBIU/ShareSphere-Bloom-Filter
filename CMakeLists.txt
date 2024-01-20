cmake_minimum_required(VERSION 3.14)
project("Facebook-Project")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Source files
set(SOURCE_FILES
        # this is where the code we want to test
        src/bloom_filter.cpp src/bloom_filter.h src/main.cpp src/Runner.cpp src/Runner.h src/Input.cpp src/Input.h src/AddURLCommand.cpp src/AddURLCommand.h src/ICommand.h src/ContainsURLCommand.cpp src/ContainsURLCommand.h)

set(SOURCE_FILES_TEST
        # this is where the code we want to test
        src/bloom_filter.cpp src/bloom_filter.h src/Runner.cpp src/Runner.h src/Input.cpp src/Input.h src/AddURLCommand.cpp src/AddURLCommand.h src/ICommand.h src/ContainsURLCommand.cpp src/ContainsURLCommand.h)

# Test files
set(TEST_FILES
        # this is the main for tests
        # this file contains the tests
        tests/test_main.cpp tests/bf_test.cpp tests/input_test.cpp)

# Create the test executable
add_executable(BFTests ${TEST_FILES} ${SOURCE_FILES_TEST})
add_executable(RUN ${SOURCE_FILES})

# Link Google Test to the test executable
target_link_libraries(BFTests PRIVATE gtest gtest_main)

# Include the source directory for tests
target_include_directories(BFTests PRIVATE src)

# Discover and run tests using Google Test
include(GoogleTest)
gtest_discover_tests(BFTests)