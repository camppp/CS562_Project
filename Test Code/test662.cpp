#include <algorithm>
#include <vector>
#include <string>

struct SettingChange {
    std::string name;
    int value;  // Assuming the value type is int for demonstration purposes
};

struct SettingsChanges {
    std::vector<SettingChange> changes;
};

struct StorageDefinition {
    SettingsChanges* settings;
    void set(SettingsChanges* settings, int value) {
        // Implementation of set function
    }
};

void ADD_IF_ABSENT(StorageDefinition& storage_def, const std::string& name, int value) {
    SettingsChanges& changes = storage_def.settings->changes;
    if (std::find_if(changes.begin(), changes.end(),
                     [&name](const SettingChange& c) { return c.name == name; }) == changes.end()) {
        changes.push_back(SettingChange{name, value});
    }
}
