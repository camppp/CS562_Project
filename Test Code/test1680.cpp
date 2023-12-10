#include <GL/glew.h>

namespace sgl {
    enum class FrameTextureType {
        Type1,
        Type2,
        Type3,
        // ... other enum values
    };

    GLuint MapEnumToTextureTarget(FrameTextureType frame_texture_type) {
        int value = static_cast<int>(frame_texture_type);
        if (value >= 0) {
            return GL_TEXTURE_CUBE_MAP_POSITIVE_X + value;
        }
        return GL_TEXTURE_2D;
    }
} // End namespace sgl.
