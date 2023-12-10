#include <string>
#include <vector>
#include <map>
#include <iostream>

class ConnectorOperator {
public:
    // Constructor
    ConnectorOperator(const std::string& name, const std::string& type) : name_(name), type_(type) {}

    // Overloaded assignment operator
    ConnectorOperator& operator=(const ConnectorOperator& other) {
        name_ = other.name_;
        type_ = other.type_;
        return *this;
    }

    // Getter methods
    const std::string& getName() const { return name_; }
    const std::string& getType() const { return type_; }

private:
    std::string name_;
    std::string type_;
};

class MarketoConnectorOperatorMapper {
public:
    static std::string getType(const std::string& name) {
        std::map<std::string, std::string> mappings = {
            {"Marketo", "MarketoConnectorOperator"},
            {"Salesforce", "SalesforceConnectorOperator"},
            {"Zoho", "ZohoConnectorOperator"}
        };
        return mappings[name];
    }
};

class S3ConnectorOperatorMapper {
public:
    static std::string getType(const std::string& name) {
        std::map<std::string, std::string> mappings = {
            {"S3", "S3ConnectorOperator"},
            {"Azure", "AzureConnectorOperator"},
            {"Google", "GoogleConnectorOperator"}
        };
        return mappings[name];
    }
};

int main() {
    // Create a JSON object with connector operator information
    std::string json = "{\"name\": \"Marketo\", \"type\": \"MarketoConnectorOperator\"}";

    // Parse the JSON object and create a ConnectorOperator object
    nlohmann::json jsonObject = nlohmann::json::parse(json);
    ConnectorOperator connectorOperator(jsonObject["name"], jsonObject["type"]);

    // Assign the connector operator values based on the JSON input
    connectorOperator = connectorOperator.getType() == "MarketoConnectorOperator"
        ? MarketoConnectorOperatorMapper::getType(connectorOperator.getName())
        : S3ConnectorOperatorMapper::getType(connectorOperator.getName());

    // Print the connector operator values
    std::cout << "Connector Operator Name: " << connectorOperator.getName() << std::endl;
    std::cout << "Connector Operator Type: " << connectorOperator.getType() << std::endl;

    return 0;
}
