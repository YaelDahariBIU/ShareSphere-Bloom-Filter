#ifndef FACEBOOK_PROJECT_INPUT_H
#define FACEBOOK_PROJECT_INPUT_H
#include <string>
#include <vector>

using namespace std;
/**class Input: this class gets input from the user, the first line of input
 * (size of has and number hash functions, and the lines after including
 * commands and the urls).**/
class Input {
private:
    //getting the size
    int size;
    //getting the number of hash functions
    int numOfHashFuns;
    //getting the vector of the hash the user asked for
    vector<int> hashFuns;
    //TODO::setting size of the input?????
    void setSize(int s);
    //TODO::?????
    void setHashFuns(vector<int> hf);

public:
    explicit Input(int num);

    Input();

    vector<int> getHashFuns();
    void init() noexcept;
    vector<string> getNext();
    int getSize() const;
};


#endif //FACEBOOK_PROJECT_INPUT_H
