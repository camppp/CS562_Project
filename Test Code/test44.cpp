std::vector<nlohmann::json> filterJSON(const std::vector<nlohmann::json>& dataArray, const Scale& xScale) {
    std::vector<nlohmann::json> filteredData;
    for (const auto& data : dataArray) {
        if (xScale.GetType() == Scale::Category) {
            if (data["xScale"].get<int>() >= xScale.min && data["xScale"].get<int>() <= xScale.max) {
                filteredData.push_back(data);
            }
        } else {
            if (data["xScale"].get<double>() >= xScale.min && data["xScale"].get<double>() <= xScale.max) {
                filteredData.push_back(data);
            }
        }
    }
    return filteredData;
}
