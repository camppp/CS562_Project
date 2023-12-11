c
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct {
    char data[BUFFER_SIZE];
    int start;
    int end;
    int length;
} CircularBuffer;

void initCircularBuffer(CircularBuffer* buffer) {
    buffer->start = 0;
    buffer->end = 0;
    buffer->length = 0;
}

void write(CircularBuffer* buffer, const char* data, int length) {
    int i;
    for (i = 0; i < length; i++) {
        buffer->data[buffer->end++] = data[i];
        if (buffer->end == BUFFER_SIZE) {
            buffer->end = 0;
        }
        buffer->length++;
    }
}

void read(CircularBuffer* buffer, char* output, int length) {
    int i;
    for (i = 0; i < length; i++) {
        output[i] = buffer->data[buffer->start++];
        if (buffer->start == BUFFER_SIZE) {
            buffer->start = 0;
        }
        buffer->length--;
    }
}

int main() {
    CircularBuffer buffer;
    initCircularBuffer(&buffer);

    char data[] = "Hello, World!";
    write(&buffer, data, strlen(data));

    char output[BUFFER_SIZE];
    read(&buffer, output, BUFFER_SIZE);

    printf("%s\n", output);

    return 0;
}
