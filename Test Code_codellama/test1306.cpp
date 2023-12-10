void WriteVersion(double maxVersion) {
    ofstream file("version.txt");
    file << "MaxVersion=" << maxVersion << endl;
    file.close();
}
