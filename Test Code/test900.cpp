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
    memset(buffer->data, 0, BUFFER_SIZE);
}

void write(CircularBuffer* buffer, const char* data, int length) {
    for (int i = 0; i < length; i++) {
        buffer->data[buffer->end] = data[i];
        buffer->end = (buffer->end + 1) % BUFFER_SIZE;
        if (buffer->length < BUFFER_SIZE) {
            buffer->length++;
        } else {
            buffer->start = (buffer->start + 1) % BUFFER_SIZE;
        }
    }
}

void read(CircularBuffer* buffer, char* output, int length) {
    for (int i = 0; i < length && i < buffer->length; i++) {
        output[i] = buffer->data[(buffer->start + i) % BUFFER_SIZE];
    }
}
