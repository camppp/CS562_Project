#include <iostream>
#include <vector>
#include <cmath>

class Particle {
 public:
  Particle(double pt, double eta, double phi, std::map<std::string, double> properties)
      : pt_(pt), eta_(eta), phi_(phi), properties_(properties) {}

  double pt() const { return pt_; }
  double eta() const { return eta_; }
  double phi() const { return phi_; }
  const std::map<std::string, double>& properties() const { return properties_; }

 private:
  double pt_;
  double eta_;
  double phi_;
  std::map<std::string, double> properties_;
};

std::vector<double> calculate_isolation_sum(const std::vector<Particle>& particles) {
  std::vector<double> isolation_sums;
  for (const auto& particle : particles) {
    double isolation_sum = 0;
    for (const auto& other_particle : particles) {
      if (other_particle != particle) {
        double dR = std::sqrt(std::pow(other_particle.eta() - particle.eta(), 2) +
                              std::pow(other_particle.phi() - particle.phi(), 2));
        if (dR < 0.4) {
          isolation_sum += other_particle.pt();
        }
      }
    }
    isolation_sums.push_back(isolation_sum);
  }
  return isolation_sums;
}

int main() {
  std::vector<Particle> particles = {
      Particle(30, 0.5, 1.2, {{"property1", 10}, {"property2", 20}}),
      Particle(25, -0.7, 2.5, {{"property1", 30}, {"property2", 40}}),
      Particle(20, 0.2, 3.8, {{"property1", 50}, {"property2", 60}}),
  };

  std::vector<double> isolation_sums = calculate_isolation_sum(particles);
  for (const auto& isolation_sum : isolation_sums) {
    std::cout << isolation_sum << std::endl;
  }

  return 0;
}
