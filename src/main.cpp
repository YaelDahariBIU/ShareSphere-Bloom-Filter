#include <iostream>
#include "header/bloom_filter.h"
#include "header/Input.h"

int main() {
//    app();
    Input i = Input(2);
    i.init();
    cout << i.getSize() << endl;
    for (const int& s : i.getHashFuns()) {
        cout << s;
        cout << " ";
    }
    return 0;
}
