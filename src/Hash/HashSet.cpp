#include "HashSet.h"
#include "HashOne.h"
#include "HashTwo.h"


HashSet::HashSet() {
    //adding all existing hash functions to the map.
    IHash* hashOne = new HashOne();
    hashCollection.insert({1, hashOne});
    IHash* hashTwo = new HashTwo();
    hashCollection.insert({2, hashTwo});
}

//return the hashing result from a certain function.
size_t HashSet::getHashed(int hashNum, string url) {
    return hashCollection[hashNum]->hashing(url);
}
//return size of map.
int HashSet::getSize() {
    return (int) hashCollection.size();
}

