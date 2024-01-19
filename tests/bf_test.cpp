//
// Created by Tal on 12/01/2024.
//
#include <gtest/gtest.h>
#include "bloom_filter.h"
#include <list>

TEST(BFTest, BasicTest) {
    list<string> lst;
    int arr[100];
    hash <string> firstHash;
    addBlackList(arr, 1, "test.com", 100, &lst, firstHash);
    ASSERT_EQ(isBlackListed("test.com", &lst), true);
    ASSERT_FALSE(isBlackListed("test1.com", &lst));
    addBlackList(arr, 1, "test1.com", 100, &lst, firstHash);
    ASSERT_EQ(isBlackListed("test1.com", &lst), true);
}

TEST(BFTest, TwoHash) {
    list<string> lst;
    int arr[100];
    hash <string> firstHash;
    addBlackList(arr, 2, "test.com", 100, &lst, firstHash);
    ASSERT_EQ(isBlackListed("test.com", &lst), true);
    ASSERT_FALSE(isBlackListed("test1.com", &lst));
    addBlackList(arr, 2, "test1.com", 100, &lst, firstHash);
    ASSERT_EQ(isBlackListed("test1.com", &lst), true);
}

TEST(BFTest, OneTwoHash) {
    list<string> lst;
    int arr[100];
    hash <string> firstHash;
    addBlackList(arr, 3, "test.com", 100, &lst, firstHash);
    ASSERT_EQ(isBlackListed("test.com", &lst), true);
    ASSERT_FALSE(isBlackListed("test1.com", &lst));
    addBlackList(arr, 3, "test1.com", 100, &lst, firstHash);
    ASSERT_EQ(isBlackListed("test1.com", &lst), true);
}

TEST(BFTEST, FalsePositive) {
    list<string> lst;
    int arr[100];
    hash <string> firstHash;
    addBlackList(arr, 1, "test.com", 100, &lst, firstHash);
    ASSERT_EQ(checkFalsePositive(arr, 100, &lst,1, "test.com", firstHash),
              "true true");
    ASSERT_EQ(checkFalsePositive(arr,100, &lst,1, "test2.com", firstHash),
              "false"); //check if
    // it's not true false case
    ASSERT_EQ(checkFalsePositive(arr,100, &lst,1, "test.com", firstHash),
              "true false");//how
    // do I write true false string?
}

TEST(HashTest, BasicTests) {
    oneHash hashOne = new oneHash();
    ASSERT_EQ(hashOne.hash("www.com"), 3);
    ASSERT_EQ(hashOne.hash("www.com2")!=3, true);
    twoHash hashTwo = new oneHash();
    ASSERT_EQ(hashOne.hash("www.com"), 10);
    ASSERT_EQ(hashOne.hash("www.com2")!=10, true);
}

TEST(BloomFilterArrayTest, BasicTests) {
    BloomFilterArray bmArray = new BloomFilterArray(100);
    bmArray.lightBit(10);
    ASSERT_EQ(bmArray.isBitLit(10), true);
    ASSERT_EQ(bmArray.isBitLit(11), false);
    bmArray.lightBit(11);
    ASSERT_EQ(bmArray.isBitLit(11), true);
}





