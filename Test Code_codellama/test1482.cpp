c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

#define BAUDRATE 9600
#define DATABITS 8
#define STOPBITS 1
#define PARITY 'N'

// Initialize the serial port with the specified baud rate and settings
void serial_init(int fd) {
    struct termios tty;
    memset(&tty, 0, sizeof tty);
    if (tcgetattr(fd, &tty) != 0) {
        perror("Error getting serial port attributes");
        return;
    }
    cfsetospeed(&tty, BAUDRATE);
    cfsetispeed(&tty, BAUDRATE);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ECHOE;
    tty.c_lflag &= ~ECHOK;
    tty.c_lflag &= ~ECHONL;
    tty.c_lflag &= ~ISIG;
    tty.c_lflag &= ~IEXTEN;
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 5;
    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("Error setting serial port attributes");
        return;
    }
}

// Send data over the serial connection
void serial_send(int fd, char *data, int length) {
    if (write(fd, data, length) != length) {
        perror("Error sending data over serial connection");
    }
}

// Receive data from the serial connection
void serial_receive(int fd, char *data, int length) {
    if (read(fd, data, length) != length) {
        perror("Error receiving data over serial connection");
    }
}

// Example usage:
int main() {
    int fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd == -1) {
        perror("Error opening serial port");
        return 1;
    }
    serial_init(fd);
    char data[] = "Hello, world!";
    serial_send(fd, data, strlen(data));
    char received_data[100];
    serial_receive(fd, received_data, 100);
    printf("Received data: %s\n", received_data);
    close(fd);
    return 0;
}
