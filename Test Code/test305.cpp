#include <iostream>

class Data {
public:
    int data[4];
};

class revMatrix44 {
public:
    int m[4][4];
    void transpose();
    ~revMatrix44();
};

void revMatrix44::transpose() {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            std::swap(m[i][j], m[j][i]);
        }
    }
}

revMatrix44::~revMatrix44() {
    // No need to do anything here
}
