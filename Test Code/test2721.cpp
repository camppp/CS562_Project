c
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

bool setBaudRate(int m_fileDescriptor, int baudRate)
{
    struct termios tty;
    memset(&tty, 0, sizeof(tty));

    if (tcgetattr(m_fileDescriptor, &tty) != 0)
    {
        return false;
    }

    switch (baudRate)
    {
        case 115200:
            cfsetispeed(&tty, B115200);
            cfsetospeed(&tty, B115200);
            break;
        case 230400:
            cfsetispeed(&tty, B230400);
            cfsetospeed(&tty, B230400);
            break;
        case 460800:
            cfsetispeed(&tty, B460800);
            cfsetospeed(&tty, B460800);
            break;
        case 921600:
            cfsetispeed(&tty, B921600);
            cfsetospeed(&tty, B921600);
            break;
        default:
            return false;
    }

    if (tcsetattr(m_fileDescriptor, TCSANOW, &tty) != 0)
    {
        return false;
    }

    return true;
}
