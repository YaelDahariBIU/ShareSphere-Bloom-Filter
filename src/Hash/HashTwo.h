#ifndef FACEBOOK_PROJECT_HASHTWO_H
#define FACEBOOK_PROJECT_HASHTWO_H


#include "IHash.h"
/**class HashTwo: this class is used to create hash objects, allowing us
 * hashing strings in different methods. the class implements the interface
 * IHash,, allowing polymorphism.**/
class HashTwo: public IHash{
private:
    hash<string> hashFunction;


public:
    HashTwo();
    size_t hashing(string) override;

};


#endif //FACEBOOK_PROJECT_HASHTWO_H
