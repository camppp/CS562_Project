class LuaFactory {
public:
    static LuaObject* createObject(const std::string& type) {
        if (type == "number") {
            return new LuaNumber();
        } else if (type == "string") {
            return new LuaString();
        } else {
            return nullptr;
        }
    }
};
