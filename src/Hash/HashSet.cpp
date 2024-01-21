#include "HashSet.h"
#include "HashOne.h"
#include "HashTwo.h"


HashSet::HashSet() {
    IHash* hashOne = new HashOne();
    hashCollection.insert({1, hashOne});
    IHash* hashTwo = new HashTwo();
    hashCollection.insert({2, hashTwo});
}

size_t HashSet::getHashed(int hashNum, string url) {
    return hashCollection[hashNum]->hashing(url);
}

int HashSet::getSize() {
    return (int) hashCollection.size();
}

