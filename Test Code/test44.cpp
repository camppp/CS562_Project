std::vector<nlohmann::json> filterJSON(const std::vector<nlohmann::json>& dataArray, const Scale& xScale) {
    std::vector<nlohmann::json> filteredData;
    for (size_t i = 0; i < dataArray.size(); ++i) {
        const nlohmann::json& groupData = dataArray[i];
        std::size_t start = 0, end = groupData.size() - 1;
        if (xScale.GetType() == Scale::Type::Category) {
            start = std::max(start, static_cast<std::size_t>(xScale.min));
            end = std::min(end, static_cast<std::size_t>(xScale.max));
        }
        nlohmann::json filteredGroupData;
        for (std::size_t j = start; j <= end; ++j) {
            filteredGroupData.push_back(groupData[j]);
        }
        filteredData.push_back(filteredGroupData);
    }
    return filteredData;
}
