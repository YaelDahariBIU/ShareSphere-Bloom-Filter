

#ifndef FACEBOOK_PROJECT_ICOMMAND_H
#define FACEBOOK_PROJECT_ICOMMAND_H
#include <string>
using namespace std;

class ICommand {
public:
    virtual void execute(string url) = 0;
};


#endif //FACEBOOK_PROJECT_ICOMMAND_H
