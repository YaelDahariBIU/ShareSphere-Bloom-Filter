#ifndef FACEBOOK_PROJECT_INPUT_H
#define FACEBOOK_PROJECT_INPUT_H
#include <string>
#include <vector>

using namespace std;

class Input {
private:
    int size;
    int numOfHashFuns;
    vector<int> hash_funs;
    void setSize(int s);
    void setHashFuns(vector<int> hf);

public:
    explicit Input(int num);
    vector<int> getHashFuns();
    void init() noexcept;
    vector<string> getNext();
    int getSize() const;
};


#endif //FACEBOOK_PROJECT_INPUT_H
