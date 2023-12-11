int AssetsFile::length() {
    int fileLength = 0;
    fileLength = AAsset_getLength(m_file);
    return fileLength;
}