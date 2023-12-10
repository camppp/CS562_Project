void processBuffer(BufferDesc* buffer_desc) {
    switch (buffer_desc->elementType) {
        case INT32:
            // Perform integer-specific operations
            break;
        case FLOAT32:
            // Perform float-specific operations
            break;
        default:
            // Handle other element types
            break;
    }
}
