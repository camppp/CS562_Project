#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

bool setBaudRate(int m_fileDescriptor, int baudRate) {
    struct termios options;
    if (tcgetattr(m_fileDescriptor, &options) != 0) {
        return false;  // Failed to get current attributes
    }

    // Set input and output baud rates
    cfsetispeed(&options, baudRate);
    cfsetospeed(&options, baudRate);

    // Apply the new baud rate settings
    if (tcsetattr(m_fileDescriptor, TCSANOW, &options) != 0) {
        return false;  // Failed to set new attributes
    }

    return true;  // Baud rate set successfully
}
