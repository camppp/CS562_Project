#include <OOLUA/Script.h>

template <typename T>
T pullLuaValue(OOLUA::Script *luaScript, const std::string& variableName)
{
    // Retrieve the value associated with the given variable name from the Lua script
    T result = luaScript->get<T>(variableName);

    // Return the retrieved value
    return result;
}
