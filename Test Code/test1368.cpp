bool EGLContextX11::Create(const ContextParams& params, WindowHandle window, const EGLContextBase* shareContext)
{
    // Initialize EGL display
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display == EGL_NO_DISPLAY) {
        // Handle error and return false
        return false;
    }

    // Initialize EGL
    EGLint majorVersion, minorVersion;
    if (!eglInitialize(display, &majorVersion, &minorVersion)) {
        // Handle error and return false
        eglTerminate(display);
        return false;
    }

    // Choose EGL configuration
    EGLConfig config;
    EGLint numConfigs;
    const EGLint configAttribs[] = {
        // Specify required configuration attributes based on params
        // e.g., EGL_RED_SIZE, EGL_GREEN_SIZE, EGL_BLUE_SIZE, etc.
        // ...

        EGL_NONE // Terminate the attribute list
    };
    if (!eglChooseConfig(display, configAttribs, &config, 1, &numConfigs)) {
        // Handle error and return false
        eglTerminate(display);
        return false;
    }

    // Create EGL context
    EGLContext context = eglCreateContext(display, config, shareContext, NULL);
    if (context == EGL_NO_CONTEXT) {
        // Handle error and return false
        eglTerminate(display);
        return false;
    }

    // Make the context current
    if (!eglMakeCurrent(display, window, window, context)) {
        // Handle error and return false
        eglDestroyContext(display, context);
        eglTerminate(display);
        return false;
    }

    // Context creation successful
    return true;
}
