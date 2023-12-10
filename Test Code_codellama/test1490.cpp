void parseFailureConnectionCondition(const std::string& input, std::string& name) {
    // Extract the entity ID and entity type from the input string
    size_t entity_id_start = input.find('=');
    size_t entity_id_end = input.find('(', entity_id_start + 1);
    size_t entity_type_start = entity_id_end + 1;
    size_t entity_type_end = input.find('(', entity_type_start + 1);

    // Extract the name from the input string
    size_t name_start = entity_type_end + 1;
    size_t name_end = input.find(')', name_start + 1);

    // Store the name in the name parameter
    name = input.substr(name_start, name_end - name_start);
}
