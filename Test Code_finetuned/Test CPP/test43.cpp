#include <nlohmann/json.hpp>
#include <vector>

class Scale {
public:
    enum Type { Category, Numeric };
    Type GetType() const { return type; }
    int min;
    int max;

private:
    Type type;
};

std::vector<nlohmann::json> filterJSON(const std::vector<nlohmann::json>& dataArray, const Scale& xScale) {
    std::vector<nlohmann::json> filteredData;

    if (xScale.GetType() == Scale::Category) {
        for (const auto& data : dataArray) {
            if (data["xScale"].get<int>() >= xScale.min && data["xScale"].get<int>() <= xScale.max) {
                filteredData.push_back(data);
            }
        }
    }

    return filteredData;
}