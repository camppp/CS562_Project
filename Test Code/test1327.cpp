#include <iostream>

class Sruba {
public:
    double kat_obrotu_sruby;

    void krec(double kat) {
        kat_obrotu_sruby += kat;
        if (kat_obrotu_sruby >= 360 || kat_obrotu_sruby <= -360) {
            kat_obrotu_sruby = 0;
            std::cout << "Screw has completed a full rotation" << std::endl;
        }
    }
};

int main() {
    Sruba screw;
    screw.kat_obrotu_sruby = 0;
    screw.krec(400);  // Output: Screw has completed a full rotation
    std::cout << "Total rotation angle: " << screw.kat_obrotu_sruby << std::endl;  // Output: 0

    screw.krec(-720);  // Output: Screw has completed a full rotation
    std::cout << "Total rotation angle: " << screw.kat_obrotu_sruby << std::endl;  // Output: 0

    screw.krec(90);  // No output
    std::cout << "Total rotation angle: " << screw.kat_obrotu_sruby << std::endl;  // Output: 90

    return 0;
}
