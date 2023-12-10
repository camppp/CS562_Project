#include <iostream>
using namespace std;

class array {
private:
    int length;
    int size;
    int *a;

public:
    array() {
        cout << "enter length: ";
        cin >> length;
        size = length;
        a = new int[length];
        cout << "enter the elements: ";
        for (int i = 0; i < length; i++) {
            cin >> a[i];
        }
    }

    void display() {
        cout << "Elements of the array: ";
        for (int i = 0; i < length; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    ~array() {
        delete[] a;
    }
};

int main() {
    array arr;
    arr.display();
    return 0;
}
