#include <iostream>
#include <string>
#include <unordered_map>

enum OpenGLFormat
{
    GL_R32I,
    GL_R32F,
    GL_RGBA8
};

enum DXGIFormat
{
    DXGI_FORMAT_R32_SINT,
    DXGI_FORMAT_R32_FLOAT,
    DXGI_FORMAT_R8G8B8A8_UNORM
};

DXGIFormat ConvertOpenGLToDXGI(OpenGLFormat glFormat)
{
    DXGIFormat dxFormat;
    switch (glFormat)
    {
        case GL_R32I:
            dxFormat = DXGI_FORMAT_R32_SINT;
            break;
        case GL_R32F:
            dxFormat = DXGI_FORMAT_R32_FLOAT;
            break;
        case GL_RGBA8:
            dxFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
            break;
        default:
            dxFormat = DXGI_FORMAT_UNKNOWN;
            break;
    }
    return dxFormat;
}

int main()
{
    OpenGLFormat glFormat = GL_RGBA8;
    DXGIFormat dxFormat = ConvertOpenGLToDXGI(glFormat);
    std::cout << "Equivalent DXGI format: " << dxFormat << std::endl;
    return 0;
}
