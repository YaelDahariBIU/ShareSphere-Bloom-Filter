#include "AddURLCommand.h"
#include "../BloomFilter/Filter.h"

void AddURLCommand::execute(string url, vector<int> hashFuns) {
    //calling the instance of filter using static method and adding url to the
    // blacklist.
    Filter* filter = Filter::getInstance();
    filter->addURL(url, hashFuns);
}
