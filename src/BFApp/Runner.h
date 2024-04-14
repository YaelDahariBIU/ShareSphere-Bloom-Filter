#ifndef FACEBOOK_PROJECT_RUNNER_H
#define FACEBOOK_PROJECT_RUNNER_H

using namespace std;
#include "../Command/ICommand.h"
#include <map>
#include <string>
#include "Input.h"

/* class Runner: this class holds the command to execute, the input from the
 * user and run function to execute commands.*/
class Runner {
public:
    map<string, ICommand*> commands;
    Input input;
    Runner();
    bool execute(const string& line);
    void init(const string& line);
};


#endif //FACEBOOK_PROJECT_RUNNER_H