void BinaryEntityPack::saveToFile(const std::string &filePath)
{
    // Open the file in binary mode for writing
    std::ofstream file(filePath, std::ios::binary);

    // Write the binary data of the entity pack to the file
    file.write(reinterpret_cast<const char*>(this->data), this->size);

    // Close the file
    file.close();
}
