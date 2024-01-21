#ifndef FACEBOOK_PROJECT_HASHONE_H
#define FACEBOOK_PROJECT_HASHONE_H


#include "IHash.h"

class HashOne: public IHash{
private:
    hash<string> hashFunction;


public:
    HashOne();
    size_t hashing(string) override;
};


#endif //FACEBOOK_PROJECT_HASHONE_H
