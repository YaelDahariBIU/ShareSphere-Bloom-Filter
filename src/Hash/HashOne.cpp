#include "HashOne.h"

//contructor
HashOne::HashOne():IHash() {
    hashFunction = hash<string>();
}

//returning hash result
size_t HashOne::hashing(string url) {
    return this->hashFunction(url);
}