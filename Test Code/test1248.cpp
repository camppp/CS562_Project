#include <iostream>
#include <dlfcn.h>
#include <string>

class DlCloseGuard {
public:
    explicit DlCloseGuard(void* handle) : handle_(handle) {}
    ~DlCloseGuard() {
        if (handle_) {
            dlclose(handle_);
        }
    }

private:
    void* handle_;
};

int main() {
    // open the library
    void* handle = dlopen("../src/libotel-cpp-lib-test_world.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return 1;
    }

    DlCloseGuard guard{handle};

    dlerror(); // reset errors

    // load the symbol
    typedef void (*world_t)();
    world_t world_func = reinterpret_cast<world_t>(dlsym(handle, "world"));
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'world': " << dlsym_error << std::endl;
        return 1;
    }

    // call the function
    world_func();

    return 0;
}
