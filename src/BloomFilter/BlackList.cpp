#include "BlackList.h"
using namespace std;

BlackList::BlackList() {
    URLs = vector<string>();
}

void BlackList::add(const string& url) {
    if(!doesExist(url)) {
        URLs.push_back(url);
    }
}

bool BlackList::doesExist(const string& url) {
    return find(URLs.begin(), URLs.end(), url) != URLs.end();
}
