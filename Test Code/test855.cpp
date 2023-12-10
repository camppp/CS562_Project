#include <iostream>
#include <vector>
#include <memory>

// Define the Plugin interface
class Plugin {
public:
    virtual void load() = 0;
    virtual void unload() = 0;
    virtual void execute() = 0;
    virtual ~Plugin() {}
};

// Define a specific plugin implementation
class SamplePlugin : public Plugin {
public:
    void load() override {
        // Perform plugin loading operations
        std::cout << "SamplePlugin loaded" << std::endl;
    }

    void unload() override {
        // Perform plugin unloading operations
        std::cout << "SamplePlugin unloaded" << std::endl;
    }

    void execute() override {
        // Perform plugin-specific functionality
        std::cout << "SamplePlugin executing specific functionality" << std::endl;
    }
};

// Application class responsible for managing plugins
class Application {
private:
    std::vector<std::unique_ptr<Plugin>> plugins;

public:
    void discoverAndLoadPlugins() {
        // Discover available plugins and load them
        plugins.push_back(std::make_unique<SamplePlugin>());
        plugins.back()->load();
    }

    void executeAllPlugins() {
        // Execute functionality of all loaded plugins
        for (const auto& plugin : plugins) {
            plugin->execute();
        }
    }

    void unloadAllPlugins() {
        // Unload all loaded plugins
        for (auto& plugin : plugins) {
            plugin->unload();
        }
        plugins.clear();
    }
};

int main() {
    Application app;
    app.discoverAndLoadPlugins();
    app.executeAllPlugins();
    app.unloadAllPlugins();
    return 0;
}
