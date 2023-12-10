#include <iostream>
#include <cstring>

class StMaker {
public:
    StMaker(const char* name) {
        // Constructor implementation for StMaker class
        // ...
    }
};

class StFpdMaker : public StMaker {
public:
    StFpdMaker(const char* name) : StMaker(name) {
        // Constructor implementation for StFpdMaker class
        // Additional initialization specific to StFpdMaker
        // ...
    }
};

int main() {
    const char* fpdName = "FPD";  // Example name for StFpdMaker
    StFpdMaker fpdMaker(fpdName); // Instantiate StFpdMaker with the given name
    // Additional operations using fpdMaker
    return 0;
}
