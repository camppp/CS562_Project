python
from typing import List

class Particle:
    def __init__(self, pt: float, eta: float, phi: float, properties: dict):
        self.pt = pt
        self.eta = eta
        self.phi = phi
        self.properties = properties

def calculate_isolation_sum(particles: List[Particle]) -> List[float]:
    isolation_sums = []
    for i, particle in enumerate(particles):
        isolation_sum = 0
        for j, other_particle in enumerate(particles):
            if i != j:
                delta_eta = particle.eta - other_particle.eta
                delta_phi = abs(particle.phi - other_particle.phi)
                if delta_phi > 3.14159:
                    delta_phi = 2 * 3.14159 - delta_phi
                delta_r = (delta_eta ** 2 + delta_phi ** 2) ** 0.5
                if delta_r < 0.4:  # Isolation cone radius
                    isolation_sum += other_particle.pt
        # Apply correction factor based on particle properties
        # isolation_sum *= correction_factor(particle.properties)
        isolation_sums.append(isolation_sum)
    return isolation_sums
