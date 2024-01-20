//
// Created by Yael Dahari on 19/01/2024.
//

#ifndef FACEBOOK_PROJECT_ADDURLCOMMAND_H
#define FACEBOOK_PROJECT_ADDURLCOMMAND_H
#include <string>
using namespace std;

#include "ICommand.h"

class AddURLCommand : public ICommand {
public:
    void execute(string url) override;
};


#endif //FACEBOOK_PROJECT_ADDURLCOMMAND_H
