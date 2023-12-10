CinderStructure::CinderReturnCodes deleteSection(const std::string& section_name) {
    // Search for the section to be deleted
    for (auto it = file_sections.begin(); it != file_sections.end(); ++it) {
        if (it->getName() == section_name) {
            // Remove the section from the file
            file_sections.erase(it);
            return CinderStructure::CinderReturnCodes::DeletedSection;
        }
    }

    // If the section is not found, return an error code
    return CinderStructure::CinderReturnCodes::SectionNotFound;
}
