#include <iostream>
#include <dlfcn.h>

int main() {
  // Load the shared library
  void* handle = dlopen("../src/libotel-cpp-lib-test_world.so", RTLD_LAZY);
  if (!handle) {
    std::cerr << "Error loading shared library: " << dlerror() << std::endl;
    return 1;
  }

  // Retrieve the function symbol
  void (*world)() = (void (*)())dlsym(handle, "world");
  if (!world) {
    std::cerr << "Error retrieving function symbol: " << dlerror() << std::endl;
    return 1;
  }

  // Call the function
  world();

  // Clean up
  dlclose(handle);

  return 0;
}
