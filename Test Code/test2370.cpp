#include <iostream>
#include <lua.hpp>

// Define the State and Type for demonstration purposes
struct State {};
using Type = int;

// Define the push function for demonstration purposes
template <typename T>
void push(State* state, T&& value) {
    // Implementation of the push function is not provided as it is specific to the project
}

void setFields(State* state, int index, Key&& key, Type&& value) {
    push(state, std::forward<Key>(key));  // Push the key onto the Lua stack
    push(state, std::forward<Type>(value));  // Push the value onto the Lua stack
    lua_rawset(state, index < 0 ? index - 2 : index);  // Set the key-value pair in the Lua table at the specified index
}

int main() {
    // Create a Lua state for demonstration purposes
    State* luaState = nullptr;

    // Assume the Lua table is already pushed onto the Lua stack at index 1
    int index = 1;
    std::string key = "example_key";
    int value = 100;

    // Call the setFields function to set the key-value pair in the Lua table
    setFields(luaState, index, std::move(key), std::move(value));

    return 0;
}
