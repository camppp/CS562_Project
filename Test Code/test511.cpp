c
#include <GL/gl.h>

void initializeTextureBuffer(const char* format_name, int texel_size_for_format, GLuint buffer_id) {
    // Calculate the size of the memory block for the texture buffer
    int size = 128 * texel_size_for_format;

    // Allocate memory for the texture buffer
    GLubyte* data = (GLubyte*)malloc(size);

    // Initialize the buffer object's data store using glBufferData
    glBufferData(GL_TEXTURE_BUFFER, size, data, GL_STATIC_DRAW);

    // Use the buffer as the texture buffer's data store
    TexBufferEXT(TEXTURE_BUFFER_EXT, format_name, buffer_id);

    // Get the number of texels in the texture buffer
    GLint num_texels;
    glGetTexLevelParameteriv(GL_TEXTURE_BUFFER, 0, GL_TEXTURE_WIDTH, &num_texels);

    // Print the number of texels in the texture buffer
    printf("Number of texels in texture buffer: %d\n", num_texels);

    // Free the memory allocated for the texture buffer
    free(data);
}
