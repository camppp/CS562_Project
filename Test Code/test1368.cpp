#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include <EGL/egl.h>

class EGLContextX11 {
public:
    bool Create(const ContextParams& params, WindowHandle window, const EGLContextBase* shareContext) {
        // Initialize the EGL display
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (display == EGL_NO_DISPLAY) {
            std::cerr << "Failed to get EGL display" << std::endl;
            return false;
        }

        // Initialize the EGL display
        EGLint major, minor;
        if (!eglInitialize(display, &major, &minor)) {
            std::cerr << "Failed to initialize EGL" << std::endl;
            return false;
        }

        // Choose an appropriate EGL configuration
        EGLConfig config;
        EGLint numConfigs;
        if (!eglChooseConfig(display, &config, 1, &numConfigs)) {
            std::cerr << "Failed to choose EGL configuration" << std::endl;
            return false;
        }

        // Create the EGL context
        EGLContext context = eglCreateContext(display, config, shareContext, NULL);
        if (context == EGL_NO_CONTEXT) {
            std::cerr << "Failed to create EGL context" << std::endl;
            return false;
        }

        // Create the EGL surface
        EGLSurface surface = eglCreateWindowSurface(display, config, window, NULL);
        if (surface == EGL_NO_SURFACE) {
            std::cerr << "Failed to create EGL surface" << std::endl;
            return false;
        }

        // Make the context current
        if (!eglMakeCurrent(display, surface, surface, context)) {
            std::cerr << "Failed to make EGL context current" << std::endl;
            return false;
        }

        // Set the context parameters
        if (!eglSetContext(display, context, params)) {
            std::cerr << "Failed to set EGL context parameters" << std::endl;
            return false;
        }

        // Return success
        return true;
    }
};
