#include <GL/glew.h>

void initializeTextureBuffer(const char* format_name, int texel_size_for_format, GLuint buffer_id) {
    // Calculate the size of the memory block
    size_t memory_size = 128 * texel_size_for_format;

    // Allocate memory for the texture buffer
    void* texture_data = malloc(memory_size);

    // Initialize the buffer object's data store using glBufferData
    glBindBuffer(GL_TEXTURE_BUFFER, buffer_id);
    glBufferData(GL_TEXTURE_BUFFER, memory_size, texture_data, GL_STATIC_DRAW);

    // Use the buffer as the texture buffer's data store by calling TexBufferEXT
    TexBufferEXT(GL_TEXTURE_BUFFER_EXT, format_name, buffer_id);

    // Free the allocated memory
    free(texture_data);
}
