#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

class LuaItemStack {
public:
    LuaItemStack(lua_State* L, int index) {
        // Create a new item stack
        lua_newtable(L);
        lua_pushvalue(L, index);
        lua_setfield(L, -2, "item");
        lua_pushvalue(L, index);
        lua_setfield(L, -2, "count");
        lua_pushvalue(L, index);
        lua_setfield(L, -2, "max_count");
        lua_pushvalue(L, index);
        lua_setfield(L, -2, "type");
    }

    ~LuaItemStack() {
        // Destroy the item stack
        lua_pushnil(L);
        lua_setfield(L, -2, "item");
        lua_pushnil(L);
        lua_setfield(L, -2, "count");
        lua_pushnil(L);
        lua_setfield(L, -2, "max_count");
        lua_pushnil(L);
        lua_setfield(L, -2, "type");
    }

    void push(lua_State* L) {
        // Push an item onto the stack
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "item");
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "count");
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "max_count");
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "type");
    }

    void pop(lua_State* L) {
        // Pop an item from the stack
        lua_pushnil(L);
        lua_setfield(L, -2, "item");
        lua_pushnil(L);
        lua_setfield(L, -2, "count");
        lua_pushnil(L);
        lua_setfield(L, -2, "max_count");
        lua_pushnil(L);
        lua_setfield(L, -2, "type");
    }

    void peek(lua_State* L) {
        // Peek at the top item on the stack
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "item");
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "count");
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "max_count");
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "type");
    }

    void clear(lua_State* L) {
        // Clear the stack
        lua_pushnil(L);
        lua_setfield(L, -2, "item");
        lua_pushnil(L);
        lua_setfield(L, -2, "count");
        lua_pushnil(L);
        lua_setfield(L, -2, "max_count");
        lua_pushnil(L);
        lua_setfield(L, -2, "type");
    }
};

void LuaItemStack_register(lua_State* L) {
    // Register the LuaItemStack class
    luaL_newmetatable(L, "LuaItemStack");
    lua_pushcfunction(L, LuaItemStack_push);
    lua_setfield(L, -2, "push");
    lua_pushcfunction(L, LuaItemStack_pop);
    lua_setfield(L, -2, "pop");
    lua_pushcfunction(L, LuaItemStack_peek);
    lua_setfield(L, -2, "peek");
    lua_pushcfunction(L, LuaItemStack_clear);
    lua_setfield(L, -2, "clear");
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    lua_pushcfunction(L, LuaItemStack_gc);
    lua_setfield(L, -2, "__gc");
}

int LuaItemStack_push(lua_State* L) {
    // Push an item onto the stack
    LuaItemStack* stack = (LuaItemStack*)lua_touserdata(L, 1);
    stack->push(L);
    return 0;
}

int LuaItemStack_pop(lua_State* L) {
    // Pop an item from the stack
    LuaItemStack* stack = (LuaItemStack*)lua_touserdata(L, 1);
    stack->pop(L);
    return 0;
}

int LuaItemStack_peek(lua_State* L) {
    // Peek at the top item on the stack
    LuaItemStack* stack = (LuaItemStack*)lua_touserdata(L, 1);
    stack->peek(L);
    return 0;
}

int LuaItemStack_clear(lua_State* L) {
    // Clear the stack
    LuaItemStack* stack = (LuaItemStack*)lua_touserdata(L, 1);
    stack->clear(L);
    return 0;
}

int LuaItemStack_gc(lua_State* L) {
    // Garbage collector for the LuaItemStack class
    LuaItemStack* stack = (LuaItemStack*)lua_touserdata(L, 1);
    delete stack;
    return 0;
}
