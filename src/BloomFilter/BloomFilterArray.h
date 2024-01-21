#ifndef FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
#define FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
#include <vector>
using namespace std;

class BloomFilterArray {
    private:
        vector<int> Bits;
    public:
        void litBit(int bitPlace);
        bool isBitLit(int bitPlace);
        size_t getSize();
};


#endif //FACEBOOK_PROJECT_BLOOMFILTERARRAY_H
