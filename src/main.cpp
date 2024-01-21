#include <iostream>
#include "header/Input.h"
#include "header/Runner.h"

int main() {
//    app();
    Input i = Input(2);
//    i.init();
//    cout << i.getSize() << endl;
//    for (const int& s : i.getHashFuns()) {
//        cout << s;
//        cout << " ";
//    }
    Runner runner = Runner(i);
    runner.run();
    return 0;
}
