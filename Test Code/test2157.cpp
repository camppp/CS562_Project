GodData GodDB::convert(const lua::ConfigTable& data, const std::string& id)
{
    // Retrieve the "legacy_id" from the Lua ConfigTable
    auto legacy_id = data.required<int>("legacy_id");

    // Create a GodData object using the provided id and the extracted legacy_id
    return GodData{SharedId{id}, legacy_id};
}
