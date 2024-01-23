#include <iostream>
#include "Filter.h"

Filter::Filter() {
    filter = BloomFilterArray();
    blackList = BlackList();
    hashSet = HashSet();
}

Filter* Filter::getInstance() {
    //creating first instance if it's the first time initializing the bject
    if (instancePtr == nullptr) {
        instancePtr = new Filter();
    }
    return instancePtr;
}

// initializing instancePtr with NULL
Filter* Filter::instancePtr = nullptr;

void Filter::addURL(const string& url, const vector<int>& hashFuns) {
    //adding url to blacklist
    blackList.add(url);
    size_t result;
    //going through the hash functions and lightning the wanted bit.
    for (int h : hashFuns) {
        //getting the index after hashing and resizing it to the array size.
        result = hashSet.getHashed(h, url);
        filter.litBit(result % filter.getSize());
    }
}

void Filter::contains(const string& url, const vector<int>& hashFuns) {
    size_t result;
    //going through all hash functions and checking if the bit is lit.
    //if one bit was not up, print false. if all are lit, check if its in the
    // list, and print result.
    for (int h : hashFuns) {
        result = hashSet.getHashed(h, url);
        // if the filter doesn't contain the result
        if (!filter.isBitLit(result % filter.getSize())) {
            cout << "false" << endl;
            return;
        }
    }
    cout << "true ";
    cout << (blackList.doesExist(url) ? "true" : "false") << endl;
}

int Filter::getHashSetSize() {
    return hashSet.getSize();
}

void Filter::setSize(int size) {
    filter = BloomFilterArray(size);
}


