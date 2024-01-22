#include "ContainsURLCommand.h"
#include "../BloomFilter/Filter.h"

void ContainsURLCommand::execute(string url, vector<int> hashFuns) {
    //checking if the url exists in the bloom filter using static method and printing result.
    Filter* filter = Filter::getInstance();
    filter->contains(url, hashFuns);
}
