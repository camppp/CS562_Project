#include <vector>

class ExtSequencer {
public:
    ExtSequencer() {
        addInstance();
    }

    ~ExtSequencer() {
        removeInstance();
    }

    void addInstance() {
        instances.push_back(this);
    }

    void removeInstance() {
        for (size_t i = 0; i < instances.size(); ++i) {
            if (instances[i] == this) {
                instances.erase(instances.begin() + i);
                break;
            }
        }
    }

    static size_t getInstanceCount() {
        return instances.size();
    }

    static void addInstance(ExtSequencer* instance) {
        instances.push_back(instance);
    }

    static void removeInstance(ExtSequencer* instance) {
        for (size_t i = 0; i < instances.size(); ++i) {
            if (instances[i] == instance) {
                instances.erase(instances.begin() + i);
                break;
            }
        }
    }

private:
    static std::vector<ExtSequencer*> instances;
};

std::vector<ExtSequencer*> ExtSequencer::instances;
