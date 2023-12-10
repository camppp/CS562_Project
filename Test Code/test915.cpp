#include <fstream>

void BinaryEntityPack::saveToFile(const std::string &filePath)
{
    std::ofstream file(filePath, std::ios::out | std::ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&entityPackData), sizeof(entityPackData)); // Assuming entityPackData is the binary data to be written
        file.close();
    } else {
        // Handle file open error
        // Example: throw an exception or return an error code
    }
}
