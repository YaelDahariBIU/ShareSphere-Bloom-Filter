#include "AddURLCommand.h"
#include "../BloomFilter/Filter.h"

void AddURLCommand::execute(string url, vector<int> hashFuns) {
    // TODO: call getInstance and invoke command
    Filter* filter = Filter::getInstance();
    filter->addURL(url, hashFuns);
}
