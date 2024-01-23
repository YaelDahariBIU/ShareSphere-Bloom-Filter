#include "BloomFilterArray.h"


//checking if the bit is lit in the vector
bool BloomFilterArray::isBitLit(int bitPlace) {
    return Bits[bitPlace]==1;
}

//lightning a bit in a specific place
void BloomFilterArray::litBit(int bitPlace) {
    Bits[bitPlace] = 1;
}

//getting the size of the vector
size_t BloomFilterArray::getSize() {
    return Bits.size();
}

//constructor with size
BloomFilterArray::BloomFilterArray(int size) {
    Bits = vector<int>(size, 0);
}
//constructor without size
BloomFilterArray::BloomFilterArray() {
    Bits = vector<int>(0, 0);
}
