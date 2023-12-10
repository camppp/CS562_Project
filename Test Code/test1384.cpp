#include "OpenJigWare.h"
#include <iostream>

int main() {
    // Initialize the OpenJigWare library
    if (!JWInitialize()) {
        std::cerr << "Failed to initialize OpenJigWare library" << std::endl;
        return 1;
    }

    // Connect to the robotic arm
    if (!JWConnect()) {
        std::cerr << "Failed to connect to the robotic arm" << std::endl;
        JWFinalize(); // Release resources before exiting
        return 1;
    }

    // Rotate the specified joints to predefined angles
    if (!JWMoveTo(1, 90) || !JWMoveTo(2, 45) || !JWMoveTo(3, 30)) {
        std::cerr << "Failed to move the robotic arm to the specified angles" << std::endl;
        JWDisconnect(); // Disconnect before releasing resources
        JWFinalize(); // Release resources before exiting
        return 1;
    }

    // Open the gripper
    if (!JWSetGripper(true)) {
        std::cerr << "Failed to open the gripper" << std::endl;
        JWDisconnect(); // Disconnect before releasing resources
        JWFinalize(); // Release resources before exiting
        return 1;
    }

    // Close the gripper
    if (!JWSetGripper(false)) {
        std::cerr << "Failed to close the gripper" << std::endl;
        JWDisconnect(); // Disconnect before releasing resources
        JWFinalize(); // Release resources before exiting
        return 1;
    }

    // Disconnect from the robotic arm
    if (!JWDisconnect()) {
        std::cerr << "Failed to disconnect from the robotic arm" << std::endl;
        JWFinalize(); // Release resources before exiting
        return 1;
    }

    // Release the resources used by the OpenJigWare library
    JWFinalize();

    std::cout << "Robotic arm control sequence completed successfully" << std::endl;

    return 0;
}
