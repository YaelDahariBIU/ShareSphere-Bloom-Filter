#ifndef FACEBOOK_PROJECT_CONTAINSURLCOMMAND_H
#define FACEBOOK_PROJECT_CONTAINSURLCOMMAND_H


#include "ICommand.h"

class ContainsURLCommand : public ICommand {
public:
    void execute(string url) override;
};


#endif //FACEBOOK_PROJECT_CONTAINSURLCOMMAND_H
