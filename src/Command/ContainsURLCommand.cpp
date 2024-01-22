#include "ContainsURLCommand.h"
#include <iostream>
#include "../BloomFilter/Filter.h"

void ContainsURLCommand::execute(string url, vector<int> hashFuns) {
    // TODO: call getInstance and invoke command
    //checking if the url exists in the bloom filter and printing result.
    cout << "check in blacklist. BlackList.contains(string url)";
    Filter* filter = Filter::getInstance();
    filter->contains(url, hashFuns);
}
