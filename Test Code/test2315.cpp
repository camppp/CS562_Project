#include "Yaml.h"

namespace execHelper::yaml {
    Yaml::Yaml(const execHelper::config::Path& file) : m_yaml(file) { ; }

    Yaml::Yaml(const std::string& yamlConfig) : m_yaml(yamlConfig) { ; }
}  // namespace execHelper::yaml
