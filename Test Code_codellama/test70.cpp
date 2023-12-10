#include <iostream>
#include <map>
#include <string>

using namespace std;

// Define a map to store the registered quantities and their units
map<string, string> quantityRegistry;

// Function to register a new physical quantity with its associated units
void registerQuantity(string name, string units) {
    quantityRegistry[name] = units;
}

// Function to return the units associated with a given quantity name
string getUnits(string name) {
    if (quantityRegistry.find(name) != quantityRegistry.end()) {
        return quantityRegistry[name];
    } else {
        return "Quantity not found";
    }
}

// Function to return a list of all registered quantities
vector<string> getAllQuantities() {
    vector<string> quantities;
    for (auto it = quantityRegistry.begin(); it != quantityRegistry.end(); ++it) {
        quantities.push_back(it->first);
    }
    return quantities;
}

int main() {
    // Register some physical quantities
    registerQuantity("Voltage", "V");
    registerQuantity("Current", "A");
    registerQuantity("Momentum", "kg m/s");
    registerQuantity("Energy", "J");
    registerQuantity("Power", "J/s");
    registerQuantity("Mass", "kg");
    registerQuantity("Area", "m^2");
    registerQuantity("Volume", "m^3");
    registerQuantity("Displacement", "m^3/rev");
    registerQuantity("Density", "kg/m^3");

    // Test the functions
    cout << getUnits("Energy") << endl; // Output: "J"
    cout << getUnits("Power") << endl; // Output: "J/s"
    cout << getUnits("Time") << endl; // Output: "Quantity not found"

    vector<string> allQuantities = getAllQuantities();
    for (string quantity : allQuantities) {
        cout << quantity << endl;
    }

    return 0;
}
