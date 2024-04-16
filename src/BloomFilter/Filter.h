#ifndef FACEBOOK_PROJECT_FILTER_H
#define FACEBOOK_PROJECT_FILTER_H


#include <mutex>
#include "BloomFilterArray.h"
#include "BlackList.h"
#include "../Hash/HashSet.h"

/** class Filter: this class holds all objects needed to run the bloom
 * filter, adding url and searching for one using the hash function as asked.
 * this class is using singleton design pattern, because we create the
 * instance of the object only once, and than getting the object using
 * static methods.
 * **/
class Filter {
private:
    BloomFilterArray filter;
    BlackList blackList;
    HashSet hashSet;
    //private constructor
    explicit Filter();
    static Filter* instancePtr;
public:
    // deleting copy constructor
    Filter(const Filter& filter) = delete;
    //returning the same instance.
    static Filter* getInstance();
    //adding url
    bool addURL(const string& url, const vector<int>& hashFuns);
    //checking if the url is in the vector
    bool contains(const string& url, const vector<int>& hashFuns);
    //get size of hashset
    int getHashSetSize();
    //creating a new bloom filter array with the size the user requested.
    void setSize(int size);
};


#endif //FACEBOOK_PROJECT_FILTER_H
