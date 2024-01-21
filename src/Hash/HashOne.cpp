#include "HashOne.h"

HashOne::HashOne():IHash() {
    hashFunction = hash<string>();
}

size_t HashOne::hashing(string url) {
    return this->hashFunction(url);
}