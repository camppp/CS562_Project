#include <dlfcn.h>
#include <iostream>

class ExtensionManager {
private:
    void* libHandle;
public:
    ExtensionManager() : libHandle(nullptr) {}

    ~ExtensionManager() {
        if (libHandle != nullptr) {
            dlclose(libHandle);
            libHandle = nullptr;
        }
    }

    bool loadLibrary(const char* filename) {
        if (libHandle != nullptr) {
            if (!unloadLibrary()) {
                return false;
            }
        }
        libHandle = dlopen(filename, RTLD_LAZY);
        return libHandle != nullptr;
    }

    bool unloadLibrary() {
        if (libHandle != nullptr) {
            if (dlclose(libHandle) == 0) {
                libHandle = nullptr;
                return true;
            }
        }
        return false;
    }

    void* getFunction(const char* functionName) {
        if (libHandle != nullptr) {
            return dlsym(libHandle, functionName);
        }
        return nullptr;
    }
};
