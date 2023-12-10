#include <string>
#include <stdexcept>

struct GUID
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

// Function to convert a hexadecimal string to GUID
GUID hexStringToGuid(const std::string& hexString)
{
    if (hexString.size() != 32) {
        throw std::invalid_argument("Invalid hexadecimal string length");
    }

    GUID result;
    int size = 16;  // Size of GUID is 16 bytes

    // Convert the hexadecimal string to GUID using the provided code snippet as reference
    for (int i = 0; i < 16; i++) {
        std::string byteStr = hexString.substr(i * 2, 2);
        result.Data4[i] = std::stoi(byteStr, 0, 16);
    }

    return result;
}
