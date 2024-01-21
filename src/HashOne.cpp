//
// Created by Tal on 21/01/2024.
//

#include "../header/HashOne.h"

HashOne::HashOne():IHash() {
    hashFunction = hash<string>();
}

size_t HashOne::hashing(string url) {
    return this->hashFunction(url);
}