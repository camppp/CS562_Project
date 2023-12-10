#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

void writePLY(const std::string& path, const cv::Mat& ply) {
    // Open the file for writing
    std::ofstream file(path, std::ios::out | std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return;
    }

    // Write the header
    file << "ply\n";
    file << "format ascii 1.0\n";
    file << "element vertex " << ply.rows << "\n";
    file << "property float x\n";
    file << "property float y\n";
    file << "property float z\n";
    file << "end_header\n";

    // Write the point cloud data
    for (int i = 0; i < ply.rows; i++) {
        file << ply.at<cv::Vec3f>(i) << "\n";
    }

    // Close the file
    file.close();
}
