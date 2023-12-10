#include <vector>
#include <string>

struct MarketData {
    // Define the structure of MarketData containing relevant market information
};

class MarketSort {
private:
    bool valid;
    std::string criterion;

public:
    const std::string MAXIMUM_TRADED = "MAXIMUM_TRADED";
    const std::string MINIMUM_TRADED = "MINIMUM_TRADED";
    const std::string FIRST_TO_START = "FIRST_TO_START";
    const std::string LAST_TO_START = "LAST_TO_START";

    MarketSort() : valid(false) {}

    MarketSort(const std::string& v) : valid(true), criterion(v) {}

    void sort(std::vector<MarketData>& data) {
        if (criterion == MAXIMUM_TRADED) {
            // Sort data based on maximum traded criterion
        } else if (criterion == MINIMUM_TRADED) {
            // Sort data based on minimum traded criterion
        } else if (criterion == FIRST_TO_START) {
            // Sort data based on first to start criterion
        } else if (criterion == LAST_TO_START) {
            // Sort data based on last to start criterion
        }
    }

    bool isValid() const {
        return valid;
    }
};
