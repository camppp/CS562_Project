Field& AtmosphereProcess::get_field_out_impl(const std::string& field_name) const {
    auto it = fields.find(field_name);
    if (it == fields.end()) {
        throw std::runtime_error("Field not found: " + field_name);
    }
    return it->second;
}
