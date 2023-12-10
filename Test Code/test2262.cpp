#include <iostream>
#include <map>
#include <string>

// ContextRegistry class
class ContextRegistry {
public:
    void registerContext(const std::string& id, void* context) {
        contexts[id] = context;
    }

    void* getContext(const std::string& id) {
        return contexts[id];
    }

    bool hasContext(const std::string& id) {
        return contexts.find(id) != contexts.end();
    }

private:
    std::map<std::string, void*> contexts;
};

// TextInput class
class TextInput {
public:
    TextInput(ContextRegistry& registry) : registry(registry) {}

    void addListener(const std::string& id) {
        registry.registerContext(id, this);
    }

    void handleTextInput(const std::string& text) {
        std::cout << "Received text input: " << text << std::endl;
    }

private:
    ContextRegistry& registry;
};

int main() {
    ContextRegistry registry;
    TextInput input(registry);

    // Register the text input context
    input.addListener("text-input");

    // Simulate text input event
    registry.getContext("text-input")->handleTextInput("Hello, world!");

    return 0;
}
