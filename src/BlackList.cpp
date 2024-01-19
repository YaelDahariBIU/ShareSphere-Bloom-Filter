//
// Created by Tal on 19/01/2024.
//

#include "../header/BlackList.h"
using namespace std;

BlackList::BlackList() {
    vectorURL = vector<string>();
}

void BlackList::add(const string& url) {
    vectorURL.push_back(url);
}

bool BlackList::doesExist(const string& url) {
    return find(vectorURL.begin(), vectorURL.end(), url) != vectorURL.end();
}
