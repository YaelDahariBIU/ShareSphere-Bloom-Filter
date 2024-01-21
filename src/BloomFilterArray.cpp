//
// Created by Tal on 19/01/2024.
//

#include "../header/BloomFilterArray.h"

//creating new bloom filter array object.
//BloomFilterArray::BloomFilterArray(int size) {
//    Bits = vector<int>(size, 0);
//}

//checking if the
bool BloomFilterArray::isBitLit(int bitPlace) {
    return Bits[bitPlace]==1;
}

void BloomFilterArray::litBit(int bitPlace) {
    Bits[bitPlace] = 1;
}

size_t BloomFilterArray::getSize() {
    return Bits.size();
}
