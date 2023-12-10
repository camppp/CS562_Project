#include <iostream>
#include <string>
#include <vector>

// Forward declaration of UML element classes
class UMLStereotype;
class UMLBehavior;
class UMLDataType;
class UMLAssociation;
class UMLInterface;
class UMLDeployment;

// UMLModelElement class
class UMLModelElement {
private:
    std::string id; // unique identifier for each UML element
    std::vector<UMLStereotype*> stereotypes;
    std::vector<UMLBehavior*> behaviors;
    std::vector<UMLDataType*> dataTypes;
    std::vector<UMLAssociation*> associations;
    std::vector<UMLInterface*> interfaces;
    std::vector<UMLDeployment*> deployments;

public:
    UMLModelElement(std::string id) : id(id) {}

    // Add stereotype to UML element
    void addStereotype(UMLStereotype* stereotype) {
        stereotypes.push_back(stereotype);
    }

    // Remove stereotype from UML element
    void removeStereotype(UMLStereotype* stereotype) {
        stereotypes.erase(std::remove(stereotypes.begin(), stereotypes.end(), stereotype), stereotypes.end());
    }

    // Get all stereotypes associated with UML element
    std::vector<UMLStereotype*> getStereotypes() {
        return stereotypes;
    }

    // Add behavior to UML element
    void addBehavior(UMLBehavior* behavior) {
        behaviors.push_back(behavior);
    }

    // Remove behavior from UML element
    void removeBehavior(UMLBehavior* behavior) {
        behaviors.erase(std::remove(behaviors.begin(), behaviors.end(), behavior), behaviors.end());
    }

    // Get all behaviors associated with UML element
    std::vector<UMLBehavior*> getBehaviors() {
        return behaviors;
    }

    // Add data type to UML element
    void addDataType(UMLDataType* dataType) {
        dataTypes.push_back(dataType);
    }

    // Remove data type from UML element
    void removeDataType(UMLDataType* dataType) {
        dataTypes.erase(std::remove(dataTypes.begin(), dataTypes.end(), dataType), dataTypes.end());
    }

    // Get all data types associated with UML element
    std::vector<UMLDataType*> getDataTypes() {
        return dataTypes;
    }

    // Add association to UML element
    void addAssociation(UMLAssociation* association) {
        associations.push_back(association);
    }

    // Remove association from UML element
    void removeAssociation(UMLAssociation* association) {
        associations.erase(std::remove(associations.begin(), associations.end(), association), associations.end());
    }

    // Get all associations associated with UML element
    std::vector<UMLAssociation*> getAssociations() {
        return associations;
    }

    // Add interface to UML element
    void addInterface(UMLInterface* interface) {
        interfaces.push_back(interface);
    }

    // Remove interface from UML element
    void removeInterface(UMLInterface* interface) {
        interfaces.erase(std::remove(interfaces.begin(), interfaces.end(), interface), interfaces.end());
    }

    // Get all interfaces associated with UML element
    std::vector<UMLInterface*> getInterfaces() {
        return interfaces;
    }

    // Add deployment to UML element
    void addDeployment(UMLDeployment* deployment) {
        deployments.push_back(deployment);
    }

    // Remove deployment from UML element
    void removeDeployment(UMLDeployment* deployment) {
        deployments.erase(std::remove(deployments.begin(), deployments.end(), deployment), deployments.end());
    }

    // Get all deployments associated with UML element
    std::vector<UMLDeployment*> getDeployments() {
        return deployments;
    }

    // Display all associated UML elements for a given UML model element
    void displayAssociatedElements() {
        std::cout << "Associated stereotypes: ";
        for (UMLStereotype* stereotype : stereotypes) {
            std::cout << stereotype->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Associated behaviors: ";
        for (UMLBehavior* behavior : behaviors) {
            std::cout << behavior->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Associated data types: ";
        for (UMLDataType* dataType : dataTypes) {
            std::cout << dataType->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Associated associations: ";
        for (UMLAssociation* association : associations) {
            std::cout << association->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Associated interfaces: ";
        for (UMLInterface* interface : interfaces) {
            std::cout << interface->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Associated deployments: ";
        for (UMLDeployment* deployment : deployments) {
            std::cout << deployment->getName() << " ";
        }
        std::cout << std::endl;
    }
};
