Field& AtmosphereProcess::get_field_out_impl(const std::string& field_name) const {
    auto it = fields.find(field_name);
    if (it != fields.end()) {
        return it->second;  // Return the reference to the found field
    } else {
        throw std::runtime_error("Field not found");  // Throw an exception if the field is not found
    }
}
