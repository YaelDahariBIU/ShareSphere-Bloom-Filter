#ifndef FACEBOOK_PROJECT_ICOMMAND_H
#define FACEBOOK_PROJECT_ICOMMAND_H
#include <string>
#include <vector>

using namespace std;
/**class ICommand: this class is used as an interface, with only one
 * function: execute. it allows doing wanted commands without specifying what
 * will make it happen.**/
class ICommand {
public:
    virtual bool execute(string url, vector<int> hashFuns) = 0;
};


#endif //FACEBOOK_PROJECT_ICOMMAND_H
