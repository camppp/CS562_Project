#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>

// AtomicOperation class
class AtomicOperation {
public:
    AtomicOperation(std::string operation, std::string data) : operation_(operation), data_(data) {}

    std::string getOperation() const { return operation_; }
    std::string getData() const { return data_; }

private:
    std::string operation_;
    std::string data_;
};

// Implementation class
class Implementation {
public:
    Implementation(std::string file_name) : file_name_(file_name) {}

    void writeAtomicOperation(const AtomicOperation& operation) {
        YAML::Emitter emitter;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "operation" << YAML::Value << operation.getOperation();
        emitter << YAML::Key << "data" << YAML::Value << operation.getData();
        emitter << YAML::EndMap;
        std::ofstream file(file_name_);
        file << emitter.c_str();
        file.close();
    }

    AtomicOperation readAtomicOperation() {
        YAML::Node node;
        std::ifstream file(file_name_);
        file >> node;
        file.close();
        return AtomicOperation(node["operation"].as<std::string>(), node["data"].as<std::string>());
    }

private:
    std::string file_name_;
};

// YamlLogger class
class YamlLogger {
public:
    YamlLogger(std::string file_name) : file_name_(file_name) {}

    void writeAtomicOperation(const AtomicOperation& operation) {
        implementation_->writeAtomicOperation(operation);
    }

    AtomicOperation readAtomicOperation() {
        return implementation_->readAtomicOperation();
    }

private:
    std::string file_name_;
    std::unique_ptr<Implementation> implementation_;
};

int main() {
    YamlLogger logger("example.yaml");
    AtomicOperation operation("add", "1 + 2");
    logger.writeAtomicOperation(operation);
    AtomicOperation read_operation = logger.readAtomicOperation();
    std::cout << read_operation.getOperation() << " " << read_operation.getData() << std::endl;
    return 0;
}
