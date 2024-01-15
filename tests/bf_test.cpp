//
// Created by Tal on 12/01/2024.
//
#include <gtest/gtest.h>
#include "bloom_filter.h"

TEST(BFTest, BasicTest) {
    ASSERT_EQ(addURL("test.com"), 1);
    ASSERT_EQ(isBlackListed("test.com"), 1);
    ASSERT_FALSE(isBlackListed("test2.com"));
}



