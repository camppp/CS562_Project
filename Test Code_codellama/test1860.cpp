class NamespaceManager {
public:
    // Constructor
    NamespaceManager() {
        // Initialize the root namespace
        root_namespace = new Namespace("root");
    }

    // Destructor
    ~NamespaceManager() {
        // Delete the root namespace
        delete root_namespace;
    }

    // Create a new namespace with the given name
    Namespace* create_namespace(const string& name) {
        // Check if the namespace already exists
        if (namespace_exists(name)) {
            throw runtime_error("Namespace already exists");
        }

        // Create a new namespace
        Namespace* new_namespace = new Namespace(name);

        // Add the new namespace to the root namespace
        root_namespace->add_sub_namespace(new_namespace);

        return new_namespace;
    }

    // Add a variable to a namespace with the given name and value
    void add_variable(const string& namespace_name, const string& variable_name, const string& variable_value) {
        // Find the namespace
        Namespace* namespace_ = find_namespace(namespace_name);

        // Check if the variable already exists
        if (namespace_->variable_exists(variable_name)) {
            throw runtime_error("Variable already exists");
        }

        // Add the variable to the namespace
        namespace_->add_variable(variable_name, variable_value);
    }

    // Retrieve the value of a variable from a namespace
    string get_variable(const string& namespace_name, const string& variable_name) {
        // Find the namespace
        Namespace* namespace_ = find_namespace(namespace_name);

        // Check if the variable exists
        if (!namespace_->variable_exists(variable_name)) {
            throw runtime_error("Variable does not exist");
        }

        // Return the variable value
        return namespace_->get_variable(variable_name);
    }

    // Create a sub-namespace within an existing namespace
    Namespace* create_sub_namespace(const string& parent_namespace_name, const string& sub_namespace_name) {
        // Find the parent namespace
        Namespace* parent_namespace = find_namespace(parent_namespace_name);

        // Check if the sub-namespace already exists
        if (parent_namespace->sub_namespace_exists(sub_namespace_name)) {
            throw runtime_error("Sub-namespace already exists");
        }

        // Create a new sub-namespace
        Namespace* new_sub_namespace = new Namespace(sub_namespace_name);

        // Add the new sub-namespace to the parent namespace
        parent_namespace->add_sub_namespace(new_sub_namespace);

        return new_sub_namespace;
    }

    // Retrieve a sub-namespace from an existing namespace
    Namespace* get_sub_namespace(const string& namespace_name, const string& sub_namespace_name) {
        // Find the namespace
        Namespace* namespace_ = find_namespace(namespace_name);

        // Check if the sub-namespace exists
        if (!namespace_->sub_namespace_exists(sub_namespace_name)) {
            throw runtime_error("Sub-namespace does not exist");
        }

        // Return the sub-namespace
        return namespace_->get_sub_namespace(sub_namespace_name);
    }

    // Delete a namespace and all its sub-namespaces
    void delete_namespace(const string& namespace_name) {
        // Find the namespace
        Namespace* namespace_ = find_namespace(namespace_name);

        // Check if the namespace exists
        if (!namespace_) {
            throw runtime_error("Namespace does not exist");
        }

        // Delete the namespace and all its sub-namespaces
        delete_namespace_recursive(namespace_);
    }

    // Display the hierarchical structure of the namespaces and their variables
    void display_hierarchy() {
        // Display the root namespace and its sub-namespaces
        display_namespace_recursive(root_namespace);
    }

private:
    // Find a namespace by its name
    Namespace* find_namespace(const string& namespace_name) {
        // Check if the namespace exists
        if (!namespace_exists(namespace_name)) {
            throw runtime_error("Namespace does not exist");
        }

        // Return the namespace
        return root_namespace->get_sub_namespace(namespace_name);
    }

    // Check if a namespace exists
    bool namespace_exists(const string& namespace_name) {
        // Check if the namespace exists in the root namespace
        if (root_namespace->sub_namespace_exists(namespace_name)) {
            return true;
        }

        // Check if the namespace exists in any of the sub-namespaces
        for (auto& sub_namespace : root_namespace->get_sub_namespaces()) {
            if (sub_namespace->sub_namespace_exists(namespace_name)) {
                return true;
            }
        }

        // The namespace does not exist
        return false;
    }

    // Delete a namespace and all its sub-namespaces recursively
    void delete_namespace_recursive(Namespace* namespace_) {
        // Delete the namespace's variables
        namespace_->delete_variables();

        // Delete the namespace's sub-namespaces
        for (auto& sub_namespace : namespace_->get_sub_namespaces()) {
            delete_namespace_recursive(sub_namespace);
        }

        // Delete the namespace
        delete namespace_;
    }

    // Display a namespace and its sub-namespaces recursively
    void display_namespace_recursive(Namespace* namespace_) {
        // Display the namespace's variables
        namespace_->display_variables();

        // Display the namespace's sub-namespaces
        for (auto& sub_namespace : namespace_->get_sub_namespaces()) {
            display_namespace_recursive(sub_namespace);
        }
    }

    // The root namespace
    Namespace* root_namespace;
};

class Namespace {
public:
    // Constructor
    Namespace(const string& name) : name(name) {}

    // Add a variable to the namespace
    void add_variable(const string& variable_name, const string& variable_value) {
        // Check if the variable already exists
        if (variable_exists(variable_name)) {
            throw runtime_error("Variable already exists");
        }

        // Add the variable to the namespace
        variables[variable_name] = variable_value;
    }

    // Retrieve the value of a variable from the namespace
    string get_variable(const string& variable_name) {
        // Check if the variable exists
        if (!variable_exists(variable_name)) {
            throw runtime_error("Variable does not exist");
        }

        // Return the variable value
        return variables[variable_name];
    }

    // Create a sub-namespace within the namespace
    Namespace* create_sub_namespace(const string& sub_namespace_name) {
        // Check if the sub-namespace already exists
        if (sub_namespace_exists(sub_namespace_name)) {
            throw runtime_error("Sub-namespace already exists");
        }

        // Create a new sub-namespace
        Namespace* new_sub_namespace = new Namespace(sub_namespace_name);

        // Add the new sub-namespace to the namespace
        sub_namespaces[sub_namespace_name] = new_sub_namespace;

        return new_sub_namespace;
    }

    // Retrieve a sub-namespace from the namespace
    Namespace* get_sub_namespace(const string& sub_namespace_name) {
        // Check if the sub-namespace exists
        if (!sub_namespace_exists(sub_namespace_name)) {
            throw runtime_error("Sub-namespace does not exist");
        }

        // Return the sub-namespace
        return sub_namespaces[sub_namespace_name];
    }

    // Delete the namespace's variables
    void delete_variables() {
        variables.clear();
    }

    // Delete the namespace's sub-namespaces
    void delete_sub_namespaces() {
        for (auto& sub_namespace : sub_namespaces) {
            delete sub_namespace.second;
        }
        sub_namespaces.clear();
    }

    // Display the namespace's variables
    void display_variables() {
        for (auto& variable : variables) {
            cout << variable.first << " = " << variable.second << endl;
        }
    }

    // Display the namespace's sub-namespaces
    void display_sub_namespaces() {
        for (auto& sub_namespace : sub_namespaces) {
            cout << sub_namespace.first << endl;
        }
    }

private:
    // The namespace's name
    string name;

    // The namespace's variables
    map<string, string> variables;

    // The namespace's sub-namespaces
    map<string, Namespace*> sub_namespaces;
};
