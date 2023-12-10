#include <iostream>
#include <map>
#include <string>

class LuaFunctionHandler {
private:
    // Map to store the Lua function handles and their corresponding register items
    std::map<std::string, void*> functionHandles;

public:
    // Set the handle and register item for the Lua function
    void _set(std::string functionName, void* handle, void* item) {
        functionHandles[functionName] = handle;
        functionHandles[functionName] = item;
    }

    // Retrieve the register item for the Lua function
    void* _getItem(std::string functionName) {
        return functionHandles[functionName];
    }
};

int main() {
    // Create an instance of the LuaFunctionHandler class
    LuaFunctionHandler lfh;

    // Set the handle and register item for a Lua function
    lfh._set("myFunction", (void*)123, (void*)456);

    // Retrieve the register item for the Lua function
    void* item = lfh._getItem("myFunction");

    // Print the register item
    std::cout << "Register item: " << item << std::endl;

    return 0;
}
