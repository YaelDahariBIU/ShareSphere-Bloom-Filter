//
// Created by Tal on 21/01/2024.
//

#include "../header/HashTwo.h"

HashTwo::HashTwo() {
    //creating new HashTwo object
    hashFunction = hash<string>();
}

size_t HashTwo::hashing(string url) {
    size_t firstHashing =  hashFunction(url);
    string urlAfterHashing = to_string(firstHashing);
    return hashFunction(urlAfterHashing);
}
