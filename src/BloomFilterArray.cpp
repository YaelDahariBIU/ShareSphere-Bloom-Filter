//
// Created by Tal on 19/01/2024.
//

#include "BloomFilterArray.h"
BloomFilterArray::BloomFilterArray(int size) {
    vectorBits=vector<int>(size, 0);
}

bool BloomFilterArray::isBitLit(int bitPlace) {
    return vectorBits.at(bitPlace)==1;
}

void BloomFilterArray::litBit(int bitPlace) {
    vectorBits[bitPlace] = 1;
}
