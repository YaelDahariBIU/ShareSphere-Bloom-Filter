#ifndef FACEBOOK_PROJECT_BLACKLIST_H
#define FACEBOOK_PROJECT_BLACKLIST_H
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*class BlackList: this class is used to hold urls, in order to know if we
 * already filtered them.*/
class BlackList {
private:
    vector<string> URLs;
public:
    //constructor for BlackList
    BlackList();
    //adding url to blacklist
    void add(const string& url);
    //checking if the url is already in the list.
    bool doesExist(const string& url);
};


#endif //FACEBOOK_PROJECT_BLACKLIST_H
