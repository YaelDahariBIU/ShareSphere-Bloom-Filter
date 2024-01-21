//
// Created by Tal on 19/01/2024.
//

#include "../header/BlackList.h"
using namespace std;

BlackList::BlackList() {
    URLs = vector<string>();
}

void BlackList::add(const string& url) {
    URLs.push_back(url);
}

bool BlackList::doesExist(const string& url) {
    return find(URLs.begin(), URLs.end(), url) != URLs.end();
}
