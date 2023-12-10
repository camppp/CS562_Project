void BindAttrib(int index, const char* name) {
    // Check if the attribute name is already bound to an index
    if (attribute_map.find(name) != attribute_map.end()) {
        // If the attribute name is already bound, throw an error
        throw std::runtime_error("Attribute name already bound to an index");
    }

    // Add the attribute name and index to the map
    attribute_map[name] = index;

    // Check if the attribute index is already bound to a name
    if (attribute_map.find(index) != attribute_map.end()) {
        // If the attribute index is already bound, throw an error
        throw std::runtime_error("Attribute index already bound to a name");
    }

    // Add the attribute index and name to the map
    attribute_map[index] = name;
}
