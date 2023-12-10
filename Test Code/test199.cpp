template <typename T>
T pullLuaValue(OOLUA::Script *luaScript, const std::string& variableName) {
    T result;
    OOLUA::pull(*luaScript, result, variableName.c_str());
    return result;
}
