//
// Created by Tal on 21/01/2024.
//

#include "../header/HashSet.h"
#include "../header/HashOne.h"
#include "../header/HashTwo.h"


HashSet::HashSet() {
    IHash* hashOne = new HashOne();
    hashCollection.insert({1, hashOne});
    IHash* hashTwo = new HashTwo();
    hashCollection.insert({2, hashTwo});
}

size_t HashSet::getHashed(int hashNum, string url) {
    return hashCollection[hashNum]->hashing(url);
}

