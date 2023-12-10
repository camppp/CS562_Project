void processUpdateRequest(const FileInfo& updatedInfo, int updateIdent, bool includePrevious, int targetChunkId) {
    // Verify that the id of the updatedInfo matches the id of the current file information
    if (updatedInfo.id != fileInfo.id) {
        throw std::runtime_error("Invalid update request: file id does not match");
    }

    // Set the current update identifier
    currentUpdateIdentifier_ = updateIdent;

    // Log an informational message indicating the received update request identifier
    std::cout << "Received update request with identifier: " << updateIdent << std::endl;

    // Update the file information with the information from updatedInfo
    fileInfo = updatedInfo;

    // Read the contents of the file specified in fileInfo.name and store it in the contents string
    std::string contents;
    std::ifstream file(fileInfo.name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    std::getline(file, contents);
    file.close();

    // Parse the contents using a parser's parseRmdSource method and store the result in currentChunks_
    currentChunks_ = parseRmdSource(contents);

    // Set the usePrevious flag to the provided includePrevious value
    usePrevious = includePrevious;

    // Set the targetId to the provided targetChunkId
    targetId = targetChunkId;
}
