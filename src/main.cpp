//
// Created by Tal on 16/01/2024.
//
#include <iostream>
#include "Hash/HashOne.h"
#include "Hash/HashTwo.h"

int main() {
    HashTwo hashTwo = HashTwo();
    cout<<hashTwo.hashing("www.com")%120;
    return 0;
}
