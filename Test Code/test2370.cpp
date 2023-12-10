void setFields(lua_State* state, int index, const char* key, const char* value) {
    lua_pushstring(state, key);
    lua_pushstring(state, value);
    lua_settable(state, index);
}
