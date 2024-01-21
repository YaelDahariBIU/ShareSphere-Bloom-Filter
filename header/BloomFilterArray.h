//
// Created by Tal on 19/01/2024.
//

#ifndef FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
#define FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
#include <vector>
using namespace std;

class BloomFilterArray {
    private:
        vector<int> Bits;
    public:
//        explicit BloomFilterArray(int size);
        void litBit(int bitPlace);
        bool isBitLit(int bitPlace);
        size_t getSize();
};


#endif //FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
