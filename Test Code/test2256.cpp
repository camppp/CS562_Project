#include <vector>
#include <string>

bool validateInputParameters(std::vector<double>& x, int np, const std::string& method) {
    if (x.empty() || np <= 0 || method.empty()) {
        return false;
    }
    return true;
}
