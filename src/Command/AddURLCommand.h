#ifndef FACEBOOK_PROJECT_ADDURLCOMMAND_H
#define FACEBOOK_PROJECT_ADDURLCOMMAND_H
#include <string>
using namespace std;

#include "ICommand.h"

class AddURLCommand : public ICommand {
public:
    void execute(string url, vector<int> hashFuns) override;
};


#endif //FACEBOOK_PROJECT_ADDURLCOMMAND_H
