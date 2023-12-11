class NamespaceManager {
public:
    // Add a new namespace with the given name
    void addNamespace(const std::string& namespaceName) {
        namespaces_[namespaceName] = Namespace();
    }

    // Remove the namespace with the given name and all its contents
    void removeNamespace(const std::string& namespaceName) {
        namespaces_.erase(namespaceName);
    }

    // Add a variable with the given name and value to the specified namespace
    void addVariable(const std::string& namespaceName, const std::string& variableName, int value) {
        namespaces_[namespaceName].variables_[variableName] = value;
    }

    // Retrieve the value of the variable with the given fully qualified name
    int getVariableValue(const std::string& fullyQualifiedName) {
        std::string namespaceName, variableName;
        std::string::size_type pos = fullyQualifiedName.find_last_of('.');
        if (pos != std::string::npos) {
            namespaceName = fullyQualifiedName.substr(0, pos);
            variableName = fullyQualifiedName.substr(pos + 1);
        } else {
            namespaceName = fullyQualifiedName;
            variableName = "";
        }

        Namespace* namespacePtr = &namespaces_[namespaceName];
        if (namespacePtr != nullptr) {
            auto it = namespacePtr->variables_.find(variableName);
            if (it != namespacePtr->variables_.end()) {
                return it->second;
            }
        }

        return 0;
    }

private:
    struct Namespace {
        std::map<std::string, int> variables_;
    };

    std::map<std::string, Namespace> namespaces_;
};
