template <typename T>
class AuxDataContainer {
public:
    void registerAuxDataType(const std::string& name) {
        // Check if the name is already registered with a different type
        if (auxDataTypes_.find(name) != auxDataTypes_.end() &&
            auxDataTypes_[name] != typeid(T)) {
            // Assertion failure with a custom message
            assert(false, "Different types registered for the same AuxData name.");
        }

        // Register the type with the name
        auxDataTypes_[name] = typeid(T);
    }

private:
    std::map<std::string, std::type_info> auxDataTypes_;
};
