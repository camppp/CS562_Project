#include <iostream>

int main() {
    int read;
    int total_read = 0;

    while (true) {
        std::cin >> read;
        if (read == -1) {
            break;
        }
        total_read += read;
    }

    std::cout << "Total amount read: " << total_read << std::endl;

    return 0;
}
