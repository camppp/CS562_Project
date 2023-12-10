#include <iostream>
#include <windows.h> // for Windows platform

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void displayShape(int tempType) {
    if (tempType == 1) {
        gotoxy(10, 10);
        std::cout << "  *  " << std::endl;
        gotoxy(10, 11);
        std::cout << " *** " << std::endl;
        gotoxy(10, 12);
        std::cout << "*****" << std::endl;
    } else if (tempType == 2) {
        gotoxy(20, 15);
        std::cout << "  ****  " << std::endl;
        gotoxy(20, 16);
        std::cout << " ****** " << std::endl;
        gotoxy(20, 17);
        std::cout << "********" << std::endl;
    } else if (tempType == 3) {
        gotoxy(5, 5);
        std::cout << "  *  " << std::endl;
        gotoxy(5, 6);
        std::cout << " *** " << std::endl;
        gotoxy(5, 7);
        std::cout << "*****" << std::endl;
    } else {
        std::cout << "Unsupported shape type" << std::endl;
    }
}

int main() {
    // Example usage
    displayShape(1); // Display shape 1 at a specific position
    displayShape(2); // Display shape 2 at a specific position
    displayShape(3); // Display shape 3 at a specific position
    return 0;
}
