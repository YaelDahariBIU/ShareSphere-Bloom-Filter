//
// Created by Yael Dahari on 19/01/2024.
//

#include "Runner.h"
#include "AddURLCommand.h"
#include "ContainsURLCommand.h"
#include "Input.h"
const int TASK = 0;
const int URL = 1;


Runner::Runner() {
    // TODO: create instance of filter
    // TODO: create input with num of funs
    ICommand* addURL = new AddURLCommand();
    commands["1"] = addURL;
    ICommand* containsURL = new ContainsURLCommand();
    commands["2"] = containsURL;
}

void Runner::run() {
    input.init();
    vector<string> command;
    while(true) {
        command = input.getNext();
        try {
            commands[command.at(TASK)]->execute(command.at(URL));
        } catch(...) {}
    }
}


