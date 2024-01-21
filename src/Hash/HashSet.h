#ifndef FACEBOOK_PROJECT_HASHSET_H
#define FACEBOOK_PROJECT_HASHSET_H
#include <string>
#include <map>
#include "IHash.h"

using namespace std;

class HashSet {
    private:
        map<int, IHash*> hashCollection;

    public:
        HashSet();
        size_t getHashed(int, string);


};


#endif //FACEBOOK_PROJECT_HASHSET_H
