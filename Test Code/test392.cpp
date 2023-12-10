CinderStructure::CinderReturnCodes deleteSection(const std::string& section_name) {
    // Find the section to be deleted
    size_t top = all.find(section_name + ":");
    if (top == std::string::npos) {
        // Section not found, return appropriate status code
        return CinderStructure::CinderReturnCodes::SectionNotFound;
    }

    // Find the end of the section
    size_t bottom = all.find(sections[i + 1].section_name + ":");
    if (bottom == std::string::npos) {
        // If the next section is not found, consider the end of the file as the bottom
        bottom = all.size();
    }

    // Erase the section from the file
    all.erase(top, bottom - top);

    // Clear the file content and write the updated content
    core_file->EmptyFile();
    core_file->Write(all);

    // Remove the section from the sections list
    sections.erase(sections.begin() + i);

    // Return the status code indicating successful deletion
    return CinderStructure::CinderReturnCodes::DeletedSection;
}
