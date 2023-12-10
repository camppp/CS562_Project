#include <iostream>
#include <string>
#include <map>
#include <vector>

// Base class for all gadgets
class Gadget {
public:
    virtual void printInfo() = 0;
};

// Derived class for CoilComputationGadget
class CoilComputationGadget : public Gadget {
public:
    void printInfo() {
        std::cout << "CoilComputationGadget" << std::endl;
    }
};

// Derived class for CapacitorComputationGadget
class CapacitorComputationGadget : public Gadget {
public:
    void printInfo() {
        std::cout << "CapacitorComputationGadget" << std::endl;
    }
};

// Gadget factory class
class GadgetFactory {
private:
    std::map<std::string, Gadget*> gadgets;

public:
    GadgetFactory() {
        // Register gadgets
        gadgets["CoilComputationGadget"] = new CoilComputationGadget();
        gadgets["CapacitorComputationGadget"] = new CapacitorComputationGadget();
    }

    // Register a new gadget
    void registerGadget(std::string name, Gadget* gadget) {
        gadgets[name] = gadget;
    }

    // Create an instance of a registered gadget
    Gadget* createGadget(std::string name) {
        return gadgets[name];
    }

    // Retrieve information about a registered gadget
    void getGadgetInfo(std::string name) {
        Gadget* gadget = gadgets[name];
        if (gadget != nullptr) {
            gadget->printInfo();
        } else {
            std::cout << "Gadget not found" << std::endl;
        }
    }
};

int main() {
    GadgetFactory factory;

    // Register a new gadget
    factory.registerGadget("CoilComputationGadget", new CoilComputationGadget());

    // Create an instance of a registered gadget
    Gadget* gadget = factory.createGadget("CoilComputationGadget");

    // Retrieve information about a registered gadget
    factory.getGadgetInfo("CoilComputationGadget");

    return 0;
}
