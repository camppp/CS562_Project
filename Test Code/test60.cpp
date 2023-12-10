int AssetsFile::length()
{
    int fileLength = 0;
    if (m_file != nullptr) {
        fileLength = AAsset_getLength(m_file);
    }
    return fileLength;
}
