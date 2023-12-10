python
class QuantityRegistry:
    def __init__(self):
        self.registry = {}

    def registerQuantity(self, name, units):
        self.registry[name] = units

    def getUnits(self, name):
        return self.registry.get(name, "Quantity not found")

    def getAllQuantities(self):
        return list(self.registry.keys())

# Usage
registry = QuantityRegistry()
registry.registerQuantity("Voltage", "V")
registry.registerQuantity("Current", "A")
registry.registerQuantity("Momentum", "kg m/s")
registry.registerQuantity("Energy", "J")
registry.registerQuantity("Power", "J/s")
registry.registerQuantity("Mass", "kg")
registry.registerQuantity("Area", "m^2")
registry.registerQuantity("Volume", "m^3")
registry.registerQuantity("Displacement", "m^3/rev")
registry.registerQuantity("Density", "kg/m^3")

print(registry.getUnits("Energy"))  # Output: "J"
print(registry.getUnits("Power"))   # Output: "J/s"
print(registry.getUnits("Time"))    # Output: "Quantity not found"

print(registry.getAllQuantities())  # Output: ["Voltage", "Current", "Momentum", "Energy", "Power", "Mass", "Area", "Volume", "Displacement", "Density"]
