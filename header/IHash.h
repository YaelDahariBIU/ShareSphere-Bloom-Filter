//
// Created by Tal on 19/01/2024.
//

#ifndef FACEBOOK_PROJECT_IHASH_H
#define FACEBOOK_PROJECT_IHASH_H
#include <string>

using namespace std;

class IHash {
private:
    hash<string> hashFunction;
public:
    // pure virtual function providing interface framework.
    virtual size_t Hashing() = 0;
};


#endif //FACEBOOK_PROJECT_IHASH_H
