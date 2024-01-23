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
        src/main.cpp src/BFApp/Runner.cpp src/BFApp/Runner.h src/BFApp/Input.cpp src/BFApp/Input.h src/Command/AddURLCommand.cpp src/Command/AddURLCommand.h src/Command/ICommand.h src/Command/ContainsURLCommand.cpp src/Command/ContainsURLCommand.h
        src/Hash/IHash.h src/Hash/HashOne.cpp src/Hash/HashOne.h src/BloomFilter/BlackList.cpp
        src/BloomFilter/BlackList.h src/BloomFilter/BloomFilterArray.cpp src/BloomFilter/BloomFilterArray.h
        src/Hash/HashTwo.cpp src/Hash/HashTwo.h src/Hash/HashSet.cpp src/Hash/HashSet.h src/BloomFilter/Filter.cpp src/BloomFilter/Filter.h
        src/Hash/HashOne.h src/Hash/HashOne.cpp src/Hash/IHash.h)

set(SOURCE_FILES_TEST
        # this is where the code we want to test
        src/BFApp/Runner.cpp src/BFApp/Runner.h src/BFApp/Input.cpp src/BFApp/Input.h src/Command/AddURLCommand.cpp src/Command/AddURLCommand.h src/Command/ICommand.h src/Command/ContainsURLCommand.cpp src/Command/ContainsURLCommand.h
        src/Hash/IHash.h src/Hash/HashOne.cpp src/Hash/HashOne.h src/BloomFilter/BlackList.cpp
        src/BloomFilter/BlackList.h src/BloomFilter/BloomFilterArray.cpp src/BloomFilter/BloomFilterArray.h
        src/Hash/HashTwo.cpp src/Hash/HashTwo.h src/Hash/HashSet.cpp src/Hash/HashSet.h src/BloomFilter/Filter.cpp src/BloomFilter/Filter.h
        src/Hash/HashOne.h src/Hash/HashOne.cpp src/Hash/IHash.h)

# Test files
set(TEST_FILES
        # this is the main for tests
        # this file contains the tests
        tests/test_main.cpp tests/input_test.cpp)      

# source files
set(BFARRAY_SRC_FILES
        # this is the main for tests
        # this file contains the tests
        src/BloomFilter/BloomFilterArray.cpp src/BloomFilter/BlackList.cpp src/BloomFilter/BlackList.h src/Hash/HashOne.cpp src/Hash/HashOne.h src/Hash/HashTwo.cpp src/Hash/HashTwo.h src/Hash/HashSet.cpp src/Hash/HashSet.h src/BloomFilter/Filter.cpp src/BloomFilter/Filter.h)
# Test files
set(BFARRAY_TEST_FILES
        # this is the main for tests
        # this file contains the tests
        tests/BFArrayTest.cpp)

# Create the test executable
add_executable(BFTests ${TEST_FILES} ${SOURCE_FILES_TEST})
add_executable(RUN ${SOURCE_FILES})
add_executable(BFARRAYTEST ${BFARRAY_TEST_FILES} ${BFARRAY_SRC_FILES})

# Link Google Test to the test executable
target_link_libraries(BFTests PRIVATE gtest gtest_main)

#adding test files
target_link_libraries(BFARRAYTEST PRIVATE gtest gtest_main)

# Include the source directory for tests
target_include_directories(BFTests PRIVATE src)

#adding source directory
target_include_directories(BFARRAYTEST PRIVATE src)

# Discover and run tests using Google Test
include(GoogleTest)
gtest_discover_tests(BFTests)

gtest_discover_tests(BFARRAYTEST)