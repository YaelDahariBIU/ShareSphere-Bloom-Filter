#ifndef FACEBOOK_PROJECT_FILTER_H
#define FACEBOOK_PROJECT_FILTER_H


#include <mutex>
#include "BloomFilterArray.h"
#include "BlackList.h"
#include "../Hash/HashSet.h"

class Filter {
private:
    BloomFilterArray filter;
    BlackList blackList;
    HashSet hashSet;
    explicit Filter();
    static Filter* instancePtr;
public:
    // deleting copy constructor
    Filter(const Filter& filter) = delete;
    static Filter* getInstance();
    void addURL(const string& url, const vector<int>& hashFuns);
    void contains(const string& url, const vector<int>& hashFuns);
};


#endif //FACEBOOK_PROJECT_FILTER_H
