#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int serial_port;

int init_serial(const char *port, speed_t baud_rate) {
    serial_port = open(port, O_RDWR);
    if (serial_port < 0) {
        perror("Error opening serial port");
        return -1;
    }

    struct termios tty;
    if (tcgetattr(serial_port, &tty) != 0) {
        perror("Error from tcgetattr");
        return -1;
    }

    cfsetospeed(&tty, baud_rate);
    cfsetispeed(&tty, baud_rate);

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        return -1;
    }

    return 0;
}

int send_data(const char *data, int length) {
    int bytes_written = write(serial_port, data, length);
    if (bytes_written < 0) {
        perror("Error writing to serial port");
        return -1;
    }
    return bytes_written;
}

int receive_data(char *buffer, int length) {
    int bytes_read = read(serial_port, buffer, length);
    if (bytes_read < 0) {
        perror("Error reading from serial port");
        return -1;
    }
    return bytes_read;
}
