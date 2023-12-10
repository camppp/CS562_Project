#include <string>
#include <vector>

class MarketData {
public:
    int maximumTraded;
    int minimumTraded;
    int firstToStart;
    int lastToStart;
};

class MarketSort {
public:
    MarketSort() : valid(false) {}
    MarketSort(const std::string& v) {
        if (v == "maximum_traded") {
            valid = true;
        } else if (v == "minimum_traded") {
            valid = true;
        } else if (v == "first_to_start") {
            valid = true;
        } else if (v == "last_to_start") {
            valid = true;
        } else {
            valid = false;
        }
    }

    void sort(std::vector<MarketData>& data) {
        if (!valid) {
            return;
        }

        if (v == "maximum_traded") {
            std::sort(data.begin(), data.end(), [](const MarketData& a, const MarketData& b) {
                return a.maximumTraded > b.maximumTraded;
            });
        } else if (v == "minimum_traded") {
            std::sort(data.begin(), data.end(), [](const MarketData& a, const MarketData& b) {
                return a.minimumTraded < b.minimumTraded;
            });
        } else if (v == "first_to_start") {
            std::sort(data.begin(), data.end(), [](const MarketData& a, const MarketData& b) {
                return a.firstToStart < b.firstToStart;
            });
        } else if (v == "last_to_start") {
            std::sort(data.begin(), data.end(), [](const MarketData& a, const MarketData& b) {
                return a.lastToStart < b.lastToStart;
            });
        }
    }

    bool isValid() const {
        return valid;
    }

private:
    bool valid;
};
