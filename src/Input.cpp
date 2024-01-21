#include "header/Input.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_ARGS = 2;
const int INVALID = 0;

Input::Input(int num) {
    size = 0;
    numOfHashFuns = num;
}


vector<int> subNums(istringstream &sentence) noexcept(false){
    vector<int> nums;
    string num;
    while(getline(sentence, num, ' ')) {
        try {
            nums.push_back(stoi(num));
        } catch (invalid_argument &argument) {
            throw argument;
        }
    }
    return nums;
}


vector<string> subWords(istringstream &sentence) {
    vector<string> words;
    string word;
    while(getline(sentence, word, ' ')) {
        words.push_back((word));
    }
    return words;
}


void Input::init() noexcept {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> nums;
    int n, first = true;
    vector<string> words = subWords(iss);
    for (const string& s : words) {
        try {
            n = stoi(s);
        } catch (exception& e) {
            init(); return;
        }
        if (first && n > INVALID) {
            setSize(n);
            first = false;
        } else if (n > numOfHashFuns || n <= INVALID) {
            init(); return;
        } else if (find(nums.begin(), nums.end(), n) == nums.end()) {
            nums.push_back(n);
        }
    }
//    if (nums.empty() || nums.size() > MAX_HASH_FUNS) {
//        init();
//    } else {
//        setHashFuns(nums);
//    }
    (nums.empty() || (nums.size() > numOfHashFuns)) ? init() : setHashFuns(nums);
}


vector<string> Input::getNext() {
    string line;
    getline(cin, line);
    istringstream sentence(line);
    vector<string> words = subWords(sentence);
    if (words.size() != MAX_ARGS) {
        return getNext();
    }
    return words;
}

vector<int> Input::getHashFuns() {
    return hashFuns;
}

void Input::setHashFuns(vector<int> hf) {
    hashFuns = std::move(hf);
}

void Input::setSize(int s) {
    size = s;
}

int Input::getSize() const {
    return size;
}



