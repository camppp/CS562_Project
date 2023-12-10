#include <string>
#include <iostream>

class PhysicsAnalysis {
private:
    std::string analysis_name;
    double luminosity;

public:
    void set_analysis_name(std::string name) {
        analysis_name = name;
    }

    void set_luminosity(double lumi) {
        luminosity = lumi;
    }

    void run(HEPUtils::Event* event) {
        // Process the event here
        std::cout << "Analysis name: " << analysis_name << std::endl;
        std::cout << "Luminosity: " << luminosity << std::endl;
    }
};
