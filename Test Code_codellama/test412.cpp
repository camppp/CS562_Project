std::map<EnumItems, std::string> generateStringMap(const EnumItems& enumItems, const std::string& displayName) {
    std::map<EnumItems, std::string> stringMap;
    for (const auto& item : enumItems) {
        stringMap[item] = displayName + "." + item.name();
    }
    return stringMap;
}
