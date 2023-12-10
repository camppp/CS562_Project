class FunctionRegistry {
public:
    void registerFunction(const std::string& name, void (*function)(void)) {
        functions[name] = function;
    }

    void invokeFunction(const std::string& name, void* args) {
        auto it = functions.find(name);
        if (it != functions.end()) {
            it->second(args);
        } else {
            throw std::runtime_error("Function not found");
        }
    }

private:
    std::map<std::string, void (*)(void)> functions;
};
