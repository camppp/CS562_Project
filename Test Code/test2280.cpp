#include <iostream>
#include <vector>
#include <memory>
#include <dlfcn.h>

// Define the Plugin interface
class Plugin {
public:
    virtual void initialize() = 0;
    virtual void release() = 0;
    virtual ~Plugin() {}
};

// Define the PluginManager class
class PluginManager {
private:
    std::vector<std::shared_ptr<Plugin>> plugins;

public:
    void loadPlugin(const std::string& pluginName) {
        void* handle = dlopen(pluginName.c_str(), RTLD_LAZY);
        if (handle) {
            using CreatePluginFunc = Plugin* (*)();
            CreatePluginFunc createPlugin = reinterpret_cast<CreatePluginFunc>(dlsym(handle, "createPlugin"));
            if (createPlugin) {
                std::shared_ptr<Plugin> plugin(createPlugin());
                plugins.push_back(plugin);
            } else {
                std::cerr << "Failed to find createPlugin function in " << pluginName << std::endl;
            }
        } else {
            std::cerr << "Failed to load " << pluginName << ": " << dlerror() << std::endl;
        }
    }

    void initializePlugins() {
        for (const auto& plugin : plugins) {
            plugin->initialize();
        }
    }

    void releasePlugins() {
        for (const auto& plugin : plugins) {
            plugin->release();
        }
    }
};

// Sample plugin implementation
extern "C" Plugin* createPlugin() {
    class SamplePlugin : public Plugin {
    public:
        void initialize() override {
            std::cout << "SamplePlugin initialized" << std::endl;
        }

        void release() override {
            std::cout << "SamplePlugin released" << std::endl;
        }
    };

    return new SamplePlugin();
}

int main() {
    PluginManager pluginManager;
    pluginManager.loadPlugin("libSamplePlugin.so");
    pluginManager.initializePlugins();
    pluginManager.releasePlugins();

    return 0;
}
