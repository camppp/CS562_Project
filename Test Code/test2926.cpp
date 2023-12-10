void writeIFToFile(const std::vector<double>& if_to_save, const std::string& filename)
{
    // Open a file stream to the specified filename
    std::ofstream aifStream(filename, std::ios::out);

    // Check if the size of the input vector matches the size of the predefined vector
    if (if_to_save.size() != AIFTimes_.size())
    {
        // Throw an exception with a descriptive error message
        throw mdm_exception(__func__, boost::format(
            "Size of IF values (%1%) does not match number of times (%2%)")
            % if_to_save.size() % AIFTimes_.size());
    }

    // Write the AIF values to the file, each value on a new line
    for (const auto& value : if_to_save)
    {
        aifStream << value << std::endl;
    }
}
