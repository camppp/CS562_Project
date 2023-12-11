#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Scale {
public:
    enum Type { Category, Numeric };

    Type GetType() const {
        return type;
    }

    int min;
    int max;

private:
    Type type;
};

std::vector<json> filterJSON(const std::vector<json>& dataArray, const Scale& xScale) {
    std::vector<json> filteredData;

    for (const auto& obj : dataArray) {
        if (obj.find("xScale") != obj.end()) {
            const json& xScaleObj = obj["xScale"];

            if (xScale.GetType() == Scale::Numeric) {
                // Numeric scale filtering
                int xScaleValue = xScaleObj.get<int>();

                if (xScaleValue >= xScale.min && xScaleValue <= xScale.max) {
                    filteredData.push_back(obj);
                }
            } else if (xScale.GetType() == Scale::Category) {
                // Category scale filtering
                std::string xScaleValue = xScaleObj.get<std::string>();

                // Assuming that the category values are strings
                if (xScaleValue >= std::to_string(xScale.min) && xScaleValue <= std::to_string(xScale.max)) {
                    filteredData.push_back(obj);
                }
            }
        }
    }

    return filteredData;
}

int main() {
    // Example usage
    std::vector<json> dataArray = {
        {{"xScale", 10}, {"value", 42}},
        {{"xScale", 5}, {"value", 24}},
        {{"xScale", "Category1"}, {"value", 36}},
        {{"xScale", "Category2"}, {"value", 18}},
    };

    Scale numericScale{Scale::Numeric, 5, 10};
    Scale categoryScale{Scale::Category, 1, 2};

    std::vector<json> filteredDataNumeric = filterJSON(dataArray, numericScale);
    std::vector<json> filteredDataCategory = filterJSON(dataArray, categoryScale);

    std::cout << "Filtered Data (Numeric Scale): " << filteredDataNumeric << std::endl;
    std::cout << "Filtered Data (Category Scale): " << filteredDataCategory << std::endl;

    return 0;
}
