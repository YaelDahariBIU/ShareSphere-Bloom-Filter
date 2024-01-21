#include <iostream>
#include "AddURLCommand.h"
#include "../BloomFilter/Filter.h"

void AddURLCommand::execute(string url, vector<int> hashFuns) {
    // TODO: call getInstance and invoke command
    cout << "adding url to BlackList.\nBlackList.addURL(string url)\n";
    Filter* filter = Filter::getInstance();
    filter->addURL(url, hashFuns);
}
