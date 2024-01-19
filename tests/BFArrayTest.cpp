//
// Created by Tal on 19/01/2024.
//

#include <gtest/gtest.h>
#include "BloomFilterArray.h"

TEST(BloomFilterArrayTest, BasicTests) {
    BloomFilterArray bmArray = BloomFilterArray(100);
    bmArray.litBit(10);
    ASSERT_EQ(bmArray.isBitLit(10), true);
    ASSERT_EQ(bmArray.isBitLit(11), false);
    bmArray.litBit(11);
    ASSERT_EQ(bmArray.isBitLit(11), true);
}
