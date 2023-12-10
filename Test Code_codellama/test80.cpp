void generateCode(const std::vector<DataEntry>& dataEntries, const std::vector<SourceLoc>& sourceLocs) {
    for (const auto& dataEntry : dataEntries) {
        // Generate regular expression code using the gen_regexp function
        gen_regexp(dataEntry.copy(allocator), dataEntry, sourceLocs[0]);
    }

    for (const auto& sourceLoc : sourceLocs) {
        // Generate conditional statement code using the gen_if function
        gen_if(sourceLoc.label, sourceLoc.var);
    }
}
