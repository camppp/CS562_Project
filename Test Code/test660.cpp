#include <iostream>

void DisplayControllerInstructions(bool m_HelpOpened) {
    if (m_HelpOpened) {
        std::cout << "How to use the controller." << std::endl;
        std::cout << "Use the mouse to look around." << std::endl;
        std::cout << "Use 'W' 'A' 'S' 'D' to move the camera." << std::endl;
    }
}
