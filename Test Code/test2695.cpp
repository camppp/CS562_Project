#include <iostream>
#include <vector>

namespace regen {
namespace c4 {

class Generator {
public:
    int data;

    void load(int n) {
        // Process and store the input data
        data = n;
    }
};

} // namespace c4
} // namespace regen

int main() {
    // Example usage
    std::vector<regen::c4::Generator> generators;
    generators.emplace_back();
    regen::c4::Generator &g = generators.back();
    g.load(10);
    std::cout << "Loaded data: " << g.data << std::endl;  // Output: Loaded data: 10
    return 0;
}
