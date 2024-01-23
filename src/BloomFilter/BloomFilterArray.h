#ifndef FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
#define FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
#include <vector>
using namespace std;
/*class BloomFilterArray: this class holds the vector of bits, we lit a bit
 * after hashing url and resize it to the array size.*/
class BloomFilterArray {
    private:
        vector<int> Bits;
    public:
        void litBit(int bitPlace);
        bool isBitLit(int bitPlace);
        size_t getSize();
        //constructor with initialize size
        BloomFilterArray(int size);
        //constructor without initialized size
        BloomFilterArray();
};


#endif //FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
