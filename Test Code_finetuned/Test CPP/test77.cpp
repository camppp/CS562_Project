#include <iostream>

class array {
private:
    int length;
    int size;
    int *a;

public:
    // Constructor
    array(int len) {
        length = len;
        size = len;
        a = new int[len];
        for (int i = 0; i < len; i++) {
            std::cout << "Enter element " << i+1 << ": ";
            std::cin >> a[i];
        }
    }

    // Destructor
    ~array() {
        delete[] a;
    }

    // Method to display the elements of the array
    void display() {
        std::cout << "Elements of the array: ";
        for (int i = 0; i < length; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int len;
    std::cout << "Enter the length of the array: ";
    std::cin >> len;
    array arr(len);
    arr.display();
    return 0;
}