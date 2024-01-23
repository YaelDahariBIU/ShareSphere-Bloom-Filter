#ifndef FACEBOOK_PROJECT_HASHSET_H
#define FACEBOOK_PROJECT_HASHSET_H
#include <string>
#include <map>
#include "IHash.h"

using namespace std;
/**class HashSet: this class collects all hash functions created in the
 * project, and allowing the user activate the function he wants, and
 * getting the result of the hash function.
 * **/
class HashSet {
    private:
        map<int, IHash*> hashCollection;

    public:
    //constructor
        HashSet();
    //returning hash result from the specified hash function.
        size_t getHashed(int, string);
        //get size of hash set.
        int getSize();

};


#endif //FACEBOOK_PROJECT_HASHSET_H
