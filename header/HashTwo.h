//
// Created by Tal on 21/01/2024.
//

#ifndef FACEBOOK_PROJECT_HASHTWO_H
#define FACEBOOK_PROJECT_HASHTWO_H


#include "IHash.h"

class HashTwo: public IHash{
private:
    hash<string> hashFunction;


public:
    HashTwo();
    size_t hashing(string) override;

};


#endif //FACEBOOK_PROJECT_HASHTWO_H
