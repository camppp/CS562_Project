std::vector<Parameter> parse_generator_output(const std::string& generator_output)
{
    // Split the generator output into individual parameters
    std::vector<std::string> parameter_strings = split(generator_output, ';');

    // Create a vector to store the parameters
    std::vector<Parameter> parameters;

    // Iterate over the parameter strings and create a Parameter object for each one
    for (const std::string& parameter_string : parameter_strings)
    {
        // Split the parameter string into its name and value
        std::vector<std::string> name_value_pair = split(parameter_string, '=');

        // Create a Parameter object with the name and value
        Parameter parameter(name_value_pair[0], name_value_pair[1]);

        // Add the parameter to the vector
        parameters.push_back(parameter);
    }

    // Return the vector of parameters
    return parameters;
}
