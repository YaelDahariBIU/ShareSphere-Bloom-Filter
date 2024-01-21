#include "Input.h"
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

/* gets a string stream and returns a vector containing each word */
vector<string> subWords(istringstream &sentence) {
    vector<string> words;
    string word;
    while(getline(sentence, word, ' ')) {
        words.push_back((word));
    }
    return words;
}

/* this function has a recursive call, calling the function again and again
until getting the input as wanted. */
void Input::init() noexcept {
    string line;
    getline(cin, line);
    istringstream sentence(line);
    vector<int> nums;
    int n, first = true;
    // sub into words
    vector<string> words = subWords(sentence);
    for (const string& s : words) {
        // try to convert to int - if not, input invalid and call recursively
        try {
            n = stoi(s);
        } catch (exception& e) {
            init(); return;
        }
        // the first number is the size, so we set it.
        if (first && n > INVALID) {
            setSize(n);
            first = false;
        }
        // if the input is invalid (bigger than hashFuns or negative)
        else if (n > numOfHashFuns || n <= INVALID) {
            init(); return;
        }
        // preventing duplicates in nums.
        else if (find(nums.begin(), nums.end(), n) == nums.end()) {
            nums.push_back(n);
        }
    }
    // dealing with nums being empty - otherwise setting hashFuns
    nums.empty() ? init() : setHashFuns(nums);
}

/* this function reads a line, divides it to words and make sure the number
 * of words is 2. otherwise calls recursively */
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



