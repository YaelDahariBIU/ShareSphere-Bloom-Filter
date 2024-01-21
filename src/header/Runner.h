#ifndef FACEBOOK_PROJECT_RUNNER_H
#define FACEBOOK_PROJECT_RUNNER_H

using namespace std;
#include "header/ICommand.h"
#include <map>
#include <string>
#include "header/Input.h"


class Runner {
public:
    map<string, ICommand*> commands;
    Input input;
    Runner(Input input);
    void run();
};


#endif //FACEBOOK_PROJECT_RUNNER_H