#include <iostream>

int a[10];

void Pred(int x) {
    int i = 0;
    while (i < 10) {
        if (a[i] == x) {
            a[i] = 0;
        } else {
            a[i] = a[i] + 1;
        }
        i++;
    }
}

int main() {
    int x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;
    Pred(x);
    std::cout << "The final state of the array a is: ";
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
