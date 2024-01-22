#ifndef FACEBOOK_PROJECT_ADDURLCOMMAND_H
#define FACEBOOK_PROJECT_ADDURLCOMMAND_H
#include <string>
using namespace std;

#include "ICommand.h"
/**class AddURLCommand: this class is used to add urls to the black list.
 * the class implements the interface ICommand, allowing polymorphism.
 * **/
class AddURLCommand : public ICommand {
public:
    void execute(string url, vector<int> hashFuns) override;
};


#endif //FACEBOOK_PROJECT_ADDURLCOMMAND_H
