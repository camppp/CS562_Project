#include <iostream>
#include <unordered_map>
#include <vector>

// Define a unique identifier for UML elements
typedef int ElementId;

namespace UML {
    class UMLModelElement {
    private:
        ElementId id;
        std::unordered_map<std::string, std::string> stereotypes;
        std::vector<std::string> behaviors;
        std::vector<std::string> dataTypes;
        std::vector<ElementId> associations;
        std::vector<std::string> interfaces;
        std::vector<std::string> deployments;

    public:
        UMLModelElement(ElementId id) : id(id) {}

        void addStereotype(const std::string& stereotype) {
            stereotypes[stereotype] = stereotype;
        }

        void addBehavior(const std::string& behavior) {
            behaviors.push_back(behavior);
        }

        void addDataType(const std::string& dataType) {
            dataTypes.push_back(dataType);
        }

        void associateElement(ElementId elementId) {
            associations.push_back(elementId);
        }

        void disassociateElement(ElementId elementId) {
            associations.erase(std::remove(associations.begin(), associations.end(), elementId), associations.end());
        }

        void addInterface(const std::string& interface) {
            interfaces.push_back(interface);
        }

        void addDeployment(const std::string& deployment) {
            deployments.push_back(deployment);
        }

        void displayAssociatedElements() {
            std::cout << "Stereotypes: ";
            for (const auto& stereotype : stereotypes) {
                std::cout << stereotype.first << " ";
            }
            std::cout << std::endl;

            std::cout << "Behaviors: ";
            for (const auto& behavior : behaviors) {
                std::cout << behavior << " ";
            }
            std::cout << std::endl;

            std::cout << "Data Types: ";
            for (const auto& dataType : dataTypes) {
                std::cout << dataType << " ";
            }
            std::cout << std::endl;

            std::cout << "Associations: ";
            for (const auto& association : associations) {
                std::cout << association << " ";
            }
            std::cout << std::endl;

            std::cout << "Interfaces: ";
            for (const auto& interface : interfaces) {
                std::cout << interface << " ";
            }
            std::cout << std::endl;

            std::cout << "Deployments: ";
            for (const auto& deployment : deployments) {
                std::cout << deployment << " ";
            }
            std::cout << std::endl;
        }
    };
}

int main() {
    // Create UML elements and associate them
    UML::UMLModelElement element1(1);
    element1.addStereotype("Entity");
    element1.addBehavior("Create");
    element1.addDataType("String");

    UML::UMLModelElement element2(2);
    element2.addStereotype("Service");
    element2.addBehavior("Update");
    element2.addDataType("Integer");

    element1.associateElement(2);
    element1.addInterface("REST");
    element2.addDeployment("AWS");

    // Display associated elements for element1
    element1.displayAssociatedElements();

    return 0;
}
