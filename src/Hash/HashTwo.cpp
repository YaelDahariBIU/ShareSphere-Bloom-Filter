#include "HashTwo.h"

HashTwo::HashTwo() {
    //creating new HashTwo object
    hashFunction = hash<string>();
}

size_t HashTwo::hashing(string url) {
    size_t firstHashing =  hashFunction(url);
    string urlAfterHashing = to_string(firstHashing);
    return hashFunction(urlAfterHashing);
}
