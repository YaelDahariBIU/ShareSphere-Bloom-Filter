#include "ContainsURLCommand.h"
#include <iostream>
#include "../BloomFilter/Filter.h"

void ContainsURLCommand::execute(string url, vector<int> hashFuns) {
    // TODO: call getInstance and invoke command
    cout << "check in blacklist. BlackList.contains(string url)";
    Filter* filter = Filter::getInstance();
    filter->contains(url, hashFuns);
}
