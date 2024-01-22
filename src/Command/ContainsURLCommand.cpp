#include "ContainsURLCommand.h"
#include "../BloomFilter/Filter.h"

void ContainsURLCommand::execute(string url, vector<int> hashFuns) {
    // call getInstance and invoke command
    Filter* filter = Filter::getInstance();
    filter->contains(url, hashFuns);
}
