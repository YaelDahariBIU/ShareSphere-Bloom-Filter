#ifndef FACEBOOK_PROJECT_IHASH_H
#define FACEBOOK_PROJECT_IHASH_H
#include <string>

using namespace std;
/**class IHash: this class is used as an interface, that every hash function
 * will implement, the class has only one function, returning the hashing
 * result.
 * **/
class IHash {
public:
    // pure virtual function providing interface framework.
    virtual size_t hashing(string) = 0;
};


#endif //FACEBOOK_PROJECT_IHASH_H
