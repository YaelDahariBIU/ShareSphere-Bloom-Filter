#include <iostream>
#include "Filter.h"

Filter::Filter() {
    filter = BloomFilterArray();
    blackList = BlackList();
    hashSet = HashSet();
}

Filter* Filter::getInstance() {
    if (instancePtr == nullptr) {
        instancePtr = new Filter();
    }
    return instancePtr;
}

// initializing instancePtr with NULL
Filter* Filter::instancePtr = nullptr;

void Filter::addURL(const string& url, const vector<int>& hashFuns) {
    blackList.add(url);
    size_t result;
    for (int h : hashFuns) {
        result = hashSet.getHashed(h, url);
        filter.litBit(result % filter.getSize());
    }
}

void Filter::contains(const string& url, const vector<int>& hashFuns) {
    size_t result;
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


