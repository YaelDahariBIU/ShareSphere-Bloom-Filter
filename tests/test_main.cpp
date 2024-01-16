//
// Created by Tal on 12/01/2024.
//
#define TEST_BUILD
#include "bloom_filter.cpp"
#include <gtest/gtest.h>
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
