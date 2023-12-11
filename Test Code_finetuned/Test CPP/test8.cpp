class MaterialInfo:
    def __init__(self):
        self.mass = 0.0
        self.restitution = 0.0
        self.angular_damping = 0.0

    def setMass(self, mass):
        self.mass = mass

    def setRestitution(self, restitution):
        self.restitution = restitution

    def setAngularDamping(self, damping):
        self.angular_damping = damping

    def getKineticEnergy(self, velocity):
        return 0.5 * self.mass * velocity**2

# Demonstration of usage
material = MaterialInfo()
material.setMass(10.0)
material.setRestitution(0.5)
material.setAngularDamping(0.1)

velocity = 10.0
kinetic_energy = material.getKineticEnergy(velocity)
print(f"Kinetic energy: {kinetic_energy}")