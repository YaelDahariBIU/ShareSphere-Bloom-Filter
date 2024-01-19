//
// Created by Tal on 19/01/2024.
//

#include "../header/BloomFilterArray.h"

//creating new bloom filter array object.
BloomFilterArray::BloomFilterArray(int size) {
    vectorBits=vector<int>(size, 0);
}

//checking if the
bool BloomFilterArray::isBitLit(int bitPlace) {
    return vectorBits[bitPlace]==1;
}

void BloomFilterArray::litBit(int bitPlace) {
    vectorBits[bitPlace] = 1;
}
