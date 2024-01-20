//
// Created by Tal on 16/01/2024.
//
#include <iostream>
#include "bloom_filter.h"
#include "Input.h"

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
