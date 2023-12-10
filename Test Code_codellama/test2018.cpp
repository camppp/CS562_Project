#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Particle {
  double x, y, vx, vy;
};

void readInput(const string& inputFile, vector<Particle>& particles) {
  ifstream file(inputFile);
  string line;
  while (getline(file, line)) {
    istringstream iss(line);
    string token;
    iss >> token;
    if (token == "particle") {
      Particle p;
      iss >> p.x >> p.y >> p.vx >> p.vy;
      particles.push_back(p);
    }
  }
}

void simulate(vector<Particle>& particles, int steps) {
  for (int i = 0; i < steps; i++) {
    for (auto& p : particles) {
      p.x += p.vx;
      p.y += p.vy;
    }
  }
}

void printFinalPositions(const vector<Particle>& particles) {
  for (const auto& p : particles) {
    cout << "Particle " << p.x << ", " << p.y << endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <input_file> <steps>" << endl;
    return 1;
  }

  string inputFile = argv[1];
  int steps = atoi(argv[2]);

  vector<Particle> particles;
  readInput(inputFile, particles);
  simulate(particles, steps);
  printFinalPositions(particles);

  return 0;
}
