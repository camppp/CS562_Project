#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Particle {
    int x, y, vx, vy;

    void step() {
        x += vx;
        y += vy;
    }
};

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "usage: " << argv[0] << " <input_file> <num_steps>" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cout << "Error: Unable to open " << argv[1] << std::endl;
        return 1;
    }

    int num_steps = std::stoi(argv[2]);

    std::vector<Particle> particles;

    std::string line;
    while (std::getline(input_file, line)) {
        if (line.find("particle") != std::string::npos) {
            Particle p;
            std::getline(input_file, line); // Read position line
            std::sscanf(line.c_str(), "  position: <%d, %d>", &p.x, &p.y);
            std::getline(input_file, line); // Read velocity line
            std::sscanf(line.c_str(), "  velocity: <%d, %d>", &p.vx, &p.vy);
            particles.push_back(p);
        }
    }

    for (int i = 0; i < num_steps; ++i) {
        for (auto& p : particles) {
            p.step();
        }
    }

    for (const auto& p : particles) {
        std::cout << "Final position: (" << p.x << ", " << p.y << ")" << std::endl;
    }

    return 0;
}
