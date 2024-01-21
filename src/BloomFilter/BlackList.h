#ifndef FACEBOOK_PROJECT_BLACKLIST_H
#define FACEBOOK_PROJECT_BLACKLIST_H
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class BlackList {
private:
    vector<string> URLs;
public:
    BlackList();
    void add(const string& url);
    bool doesExist(const string& url);
};


#endif //FACEBOOK_PROJECT_BLACKLIST_H
