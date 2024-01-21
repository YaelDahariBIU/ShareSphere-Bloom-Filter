#include "BloomFilterArray.h"


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
