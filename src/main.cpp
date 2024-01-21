#include <iostream>
#include "BFApp/Input.h"
#include "BFApp/Runner.h"

int main() {
    Input i = Input(2);
    Runner runner = Runner(i);
    runner.run();
    return 0;
}
