python
def getOpenGLFormats(channels: int) -> (str, str):
    if channels == 4:
        internalFormat = 'GL_RGBA8'
        format = 'GL_RGBA'
    elif channels == 3:
        internalFormat = 'GL_RGB8'
        format = 'GL_RGB'
    elif channels == 1:
        internalFormat = 'GL_RED'
        format = 'GL_RED'
    return (internalFormat, format)
