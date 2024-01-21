#include <stdexcept>
#include "header/Runner.h"
#include "header/AddURLCommand.h"
#include "header/ContainsURLCommand.h"
#include "header/Input.h"
#include <map>
const int TASK = 0;
const int URL = 1;


Runner::Runner(Input input) : input(input) {
    // TODO: create instance of filter
    // TODO: create input with num of funs
    ICommand* addURL = new AddURLCommand();
    commands["1"] = addURL;
    ICommand* containsURL = new ContainsURLCommand();
    commands["2"] = containsURL;
    input = Input(2);
}

void Runner::run() {
    input.init();
    vector<string> command;
    string task, url;
    while(true) {
        command = input.getNext();
        if (commands[command.at(TASK)]) {
            commands[command.at(TASK)]->execute(command.at(URL));
        }
    }
}


