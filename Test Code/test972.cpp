void try_array_block_1(void) {
    // Fill the buffer with serialized data, leaving 1 byte free
    fill_buffer_except(1);

    // Process the buffer using array blocks of size 1
    for (int i = 0; i < buffer_size; i += 1) {
        // Process the current block
        process_block(buffer + i, 1);
    }
}

void try_array_block_2(void) {
    // Fill the buffer with serialized data, leaving 2 bytes free
    fill_buffer_except(2);

    // Process the buffer using array blocks of size 2
    for (int i = 0; i < buffer_size; i += 2) {
        // Process the current block
        process_block(buffer + i, 2);
    }
}

void try_array_block_4(void) {
    // Fill the buffer with serialized data, leaving 4 bytes free
    fill_buffer_except(4);

    // Process the buffer using array blocks of size 4
    for (int i = 0; i < buffer_size; i += 4) {
        // Process the current block
        process_block(buffer + i, 4);
    }
}

void try_array_block_8(void) {
    // Fill the buffer with serialized data, leaving 8 bytes free
    fill_buffer_except(8);

    // Process the buffer using array blocks of size 8
    for (int i = 0; i < buffer_size; i += 8) {
        // Process the current block
        process_block(buffer + i, 8);
    }
}
