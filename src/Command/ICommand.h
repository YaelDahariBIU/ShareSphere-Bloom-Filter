#ifndef FACEBOOK_PROJECT_ICOMMAND_H
#define FACEBOOK_PROJECT_ICOMMAND_H
#include <string>
#include <vector>

using namespace std;

class ICommand {
public:
    virtual void execute(string url, vector<int> hashFuns) = 0;
};


#endif //FACEBOOK_PROJECT_ICOMMAND_H
