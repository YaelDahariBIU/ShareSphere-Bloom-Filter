#include "BlackList.h"
using namespace std;

//creating black list vector that will hold the urls.
BlackList::BlackList() {
    URLs = vector<string>();
}

//adding url to the list.
void BlackList::add(const string& url) {
    URLs.push_back(url);
}

//checking if the url exists in the list.
bool BlackList::doesExist(const string& url) {
    return find(URLs.begin(), URLs.end(), url) != URLs.end();
}
