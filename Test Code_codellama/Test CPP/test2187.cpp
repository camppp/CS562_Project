std::vector<std::string> extractIncludedFiles(const std::string& sourceCode) {
    std::vector<std::string> includedFiles;
    std::string::size_type pos = 0;
    while ((pos = sourceCode.find("#include", pos)) != std::string::npos) {
        pos += 8;  // skip over "#include"
        if (sourceCode[pos] == '"') {
            pos++;
            std::string::size_type endPos = sourceCode.find('"', pos);
            includedFiles.push_back(sourceCode.substr(pos, endPos - pos));
            pos = endPos + 1;
        } else if (sourceCode[pos] == '<') {
            pos++;
            std::string::size_type endPos = sourceCode.find('>', pos);
            includedFiles.push_back(sourceCode.substr(pos, endPos - pos));
            pos = endPos + 1;
        } else {
            pos++;
        }
    }
    return includedFiles;
}
