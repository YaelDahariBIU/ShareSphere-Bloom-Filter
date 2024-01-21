//
// Created by Tal on 16/01/2024.
//
#include <iostream>
#include "../header/bloom_filter.h"
#include "../header/HashOne.h"
#include "../header/HashTwo.h"

int main() {
    HashTwo hashTwo = HashTwo();
    cout<<hashTwo.hashing("www.com")%120;
    return 0;
}
