#include <iostream>
using namespace std;

class Duck {
public:
    virtual void quack() {
        cout << "Quack!!" << endl;
    }
};

class DecoyDuck : public Duck {
public:
    void quack() override {
        cout << "--------------------------------------DecoyDuck!!-------------------------------" << endl;
    }
};

int main() {
    DecoyDuck decoy;
    decoy.quack();
    return 0;
}
