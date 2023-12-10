void WriteITKtoSlicer3Lmk(const std::string& outputLandmarkFile, const std::map<std::string, std::vector<double>>& lmksMap) {
    // Open the output file for writing
    std::ofstream outputFile(outputLandmarkFile);

    // Iterate over the landmarks in the map
    for (const auto& lmk : lmksMap) {
        // Get the landmark name and coordinates
        const std::string& lmkName = lmk.first;
        const std::vector<double>& lmkCoords = lmk.second;

        // Write the landmark data to the file
        outputFile << lmkName << " " << lmkCoords[0] << " " << lmkCoords[1] << " " << lmkCoords[2] << std::endl;
    }

    // Close the output file
    outputFile.close();
}
