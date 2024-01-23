#ifndef FACEBOOK_PROJECT_CONTAINSURLCOMMAND_H
#define FACEBOOK_PROJECT_CONTAINSURLCOMMAND_H


#include "ICommand.h"
/**class ContainsURLCommand: this class is used to check if url already
 * exists in the bloom filter. the class implements ICommand interface,
 * allowing polymorphism **/
class ContainsURLCommand : public ICommand {
public:
    void execute(string url, vector<int> hashFuns) override;
};


#endif //FACEBOOK_PROJECT_CONTAINSURLCOMMAND_H
