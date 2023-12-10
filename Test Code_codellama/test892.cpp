static good_bool create_definition_footprint(const instance_collection_parameter_type& parameter, const footprint& top) {
    // Check if the parameter is valid
    if (!parameter.is_valid()) {
        return false;
    }

    // Check if the footprint is valid
    if (!top.is_valid()) {
        return false;
    }

    // Create a new definition footprint
    footprint definition_footprint;

    // Iterate over the instances in the instance collection parameter
    for (const auto& instance : parameter.instances()) {
        // Check if the instance is valid
        if (!instance.is_valid()) {
            return false;
        }

        // Add the instance to the definition footprint
        definition_footprint.add_instance(instance);
    }

    // Add the top footprint to the definition footprint
    definition_footprint.add_footprint(top);

    // Return the definition footprint
    return definition_footprint;
}
