//
// Created by Tal on 12/01/2024.
//
#include <gtest/gtest.h>
#include "../header/bloom_filter.h"
#include "../header/HashOne.h"
#include "../header/HashTwo.h"
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
    HashOne hashOne = HashOne();
    ASSERT_EQ(hashOne.hashing("www.com"), 16058600311704576603);
    ASSERT_EQ(hashOne.hashing("www.com2")!=16058600311704576603, true);
    HashTwo hashTwo = HashTwo();
    ASSERT_EQ(hashTwo.hashing("www.com"), 14602934796652375482);
    ASSERT_EQ(hashTwo.hashing("www.com2")!=14602934796652375482, true);
}





