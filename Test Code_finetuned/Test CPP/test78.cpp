void generateCode(const std::vector<DataEntry>& dataEntries, const std::vector<SourceLoc>& sourceLocs) {
    for (const auto& dataEntry : dataEntries) {
        // Generate regular expression code
        var_t var;
        gen_regexp(var, dataEntry, SourceLoc());
    }

    for (const auto& sourceLoc : sourceLocs) {
        // Generate conditional statement code
        Label* label = new Label();
        var_t var;
        gen_if(label, var);
    }
}