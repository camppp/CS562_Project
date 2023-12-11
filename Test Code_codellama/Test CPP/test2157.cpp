GodData GodDB::convert(const lua::ConfigTable& data, const std::string& id) {
    int legacy_id = data.required<int>("legacy_id");
    return GodData(SharedId(id), legacy_id);
}
