#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint32_t read_index;
    uint32_t write_index;
} circular_buffer_t;

void write_to_buffer(circular_buffer_t *buffer, uint32_t l_left, uint8_t *b_write_ptr) {
    uint32_t l_write_avail = b_write_avail(buffer);
    uint32_t l_write = l_left < l_write_avail ? l_left : l_write_avail;
    int32_t bytes_read = a_q.read(b_write_ptr, l_write);
    if (bytes_read < 0) {
        TRC_ERROR("Error reading from buffer");
        return;
    }
    buffer->write_index += bytes_read;
    if (buffer->write_index >= BUFFER_SIZE) {
        buffer->write_index -= BUFFER_SIZE;
    }
}
