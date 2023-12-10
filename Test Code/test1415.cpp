#include <iostream>

class TsDualSolenoidValveController {
public:
    TsDualSolenoidValveController() {
        // Base class constructor implementation
        std::cout << "Base class constructor called" << std::endl;
    }
    // Other member functions for controlling the valve
};

class FriendlyTsDualSolenoidValveController : public TsDualSolenoidValveController {
public:
    FriendlyTsDualSolenoidValveController() : TsDualSolenoidValveController() {
        // Derived class constructor implementation
        std::cout << "Derived class constructor called" << std::endl;
        // Additional features specific to the derived class can be initialized here
    }
};

int main() {
    FriendlyTsDualSolenoidValveController controller;
    // Output:
    // Base class constructor called
    // Derived class constructor called
    return 0;
}
