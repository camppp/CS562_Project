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
            // Handle unsupported OpenGL formats
            throw std::invalid_argument("Unsupported OpenGL format");
    }
    return dxFormat;
}
