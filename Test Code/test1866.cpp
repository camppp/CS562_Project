#include <iostream>
using namespace std;

class Tree {
private:
    static int objectCount;

public:
    Tree() {
        objectCount++;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int Tree::objectCount = 0;

int main() {
    Tree oak;
    Tree elm;
    Tree pine;

    cout << "We have " << Tree::getObjectCount() << " Trees in our program!\n";

    return 0;
}
