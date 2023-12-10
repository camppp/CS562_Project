#include <iostream>
#include <fstream>
#include <map>
#include <vector>

void WriteITKtoSlicer3Lmk(const std::string& outputLandmarkFile, const std::map<std::string, std::vector<double>>& lmksMap) {
    std::ofstream outputFile(outputLandmarkFile);
    if (outputFile.is_open()) {
        for (const auto& entry : lmksMap) {
            const std::string& landmarkName = entry.first;
            const std::vector<double>& coordinates = entry.second;
            if (coordinates.size() >= 3) {
                outputFile << landmarkName << " " << coordinates[0] << " " << coordinates[1] << " " << coordinates[2] << std::endl;
            } else {
                std::cerr << "Invalid coordinates for landmark: " << landmarkName << std::endl;
            }
        }
        outputFile.close();
    } else {
        std::cerr << "Unable to open file: " << outputLandmarkFile << std::endl;
    }
}
