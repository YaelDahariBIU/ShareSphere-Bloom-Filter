#include <stdexcept>
#include "Runner.h"
#include "../Command/AddURLCommand.h"
#include "../Command/ContainsURLCommand.h"
#include "Input.h"
#include "../BloomFilter/Filter.h"
#include <map>
const int TASK = 0;
const int URL = 1;


Runner::Runner() {
    //creating filter object running our bloom filter.
    Filter* filter = Filter::getInstance();
    //getting input from the user, max input is the number of hash functions.
    input = Input(filter->getHashSetSize());
    //adding to commands map task1: adding url and task 2: searching for url.
    ICommand* addURL = new AddURLCommand();
    commands["1"] = addURL;
    ICommand* containsURL = new ContainsURLCommand();
    commands["2"] = containsURL;
}

void Runner::run() {
    //getting first input, size of bloom filter and the hash functions we use.
    input.init();
    int size = input.getSize();
    Filter* filter = Filter::getInstance();
    filter->setSize(size);
    //reading command (1 or 2) and string url from the user.
    vector<string> command;
    string task, url;
    //running for-ever because the bloom filter is always working
    while(true) {
        //getting input from the user.
        command = input.getNext();
        //if the command exists in the map, execute.
        if (commands[command.at(TASK)]) {
            commands[command.at(TASK)]->execute(command.at(URL), input.getHashFuns());
        }
    }
}


