#ifndef FACEBOOK_PROJECT_RUNNER_H
#define FACEBOOK_PROJECT_RUNNER_H

using namespace std;
#include "../Command/ICommand.h"
#include <map>
#include <string>
#include "Input.h"


class Runner {
public:
    map<string, ICommand*> commands;
    Input input;
    Runner();
    void run();
};


#endif //FACEBOOK_PROJECT_RUNNER_H