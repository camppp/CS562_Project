#include <string>
#include <vector>
#include "execHelper/config/Path.h"
#include "execHelper/config/SettingsNode.h"

namespace execHelper::yaml {
    class Yaml {
      public:
        Yaml(const execHelper::config::Path& file) {
            // Load the YAML configuration from the file
            m_yaml = execHelper::config::SettingsNode::load(file);
        }

        Yaml(const std::string& yamlConfig) {
            // Load the YAML configuration from the string
            m_yaml = execHelper::config::SettingsNode::load(yamlConfig);
        }

        // Getter methods
        std::string getString(const std::string& key) const {
            return m_yaml.getString(key);
        }

        int getInt(const std::string& key) const {
            return m_yaml.getInt(key);
        }

        double getDouble(const std::string& key) const {
            return m_yaml.getDouble(key);
        }

        bool getBool(const std::string& key) const {
            return m_yaml.getBool(key);
        }

        std::vector<std::string> getStringList(const std::string& key) const {
            return m_yaml.getStringList(key);
        }

        // Setter methods
        void setString(const std::string& key, const std::string& value) {
            m_yaml.setString(key, value);
        }

        void setInt(const std::string& key, int value) {
            m_yaml.setInt(key, value);
        }

        void setDouble(const std::string& key, double value) {
            m_yaml.setDouble(key, value);
        }

        void setBool(const std::string& key, bool value) {
            m_yaml.setBool(key, value);
        }

        void setStringList(const std::string& key, const std::vector<std::string>& value) {
            m_yaml.setStringList(key, value);
        }

      private:
        execHelper::config::SettingsNode m_yaml;
    };
}  // namespace execHelper::yaml
