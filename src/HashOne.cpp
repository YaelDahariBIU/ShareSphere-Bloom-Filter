//
// Created by Tal on 21/01/2024.
//

#include "../header/HashOne.h"

HashOne::HashOne() {
    firstHash = hash<string>();
}

size_t HashOne::hashing(string url) {
    return firstHash(url);
}