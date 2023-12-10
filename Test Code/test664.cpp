void PointCloud::writePLY(string path, cv::Mat ply) {
  ofstream outfile(path, ios::out | ios::binary);
  if (!outfile.is_open()) {
    cerr << "Error: Unable to open file for writing" << endl;
    return;
  }

  int numPoints = ply.size().height;
  int numChannels = ply.size().width;

  // Write the PLY header
  outfile << "ply" << endl;
  outfile << "format binary_little_endian 1.0" << endl;
  outfile << "element vertex " << numPoints << endl;
  outfile << "property float x" << endl;
  outfile << "property float y" << endl;
  outfile << "property float z" << endl;
  // Add additional properties as per the channels in the input cv::Mat

  outfile << "end_header" << endl;

  // Write the point cloud data
  for (int i = 0; i < numPoints; ++i) {
    float x = ply.at<float>(i, 0);
    float y = ply.at<float>(i, 1);
    float z = ply.at<float>(i, 2);
    outfile.write(reinterpret_cast<const char*>(&x), sizeof(float));
    outfile.write(reinterpret_cast<const char*>(&y), sizeof(float));
    outfile.write(reinterpret_cast<const char*>(&z), sizeof(float));
    // Write additional channels if present in the input cv::Mat
  }

  outfile.close();
}
