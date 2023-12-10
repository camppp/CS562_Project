GUID hexStringToGuid(const std::string& hexString)
{
    // Check that the input string is a valid hexadecimal representation of a GUID
    if (hexString.size() != 32)
    {
        throw std::invalid_argument("Input string is not a valid hexadecimal representation of a GUID");
    }

    // Convert the input string to a GUID structure
    GUID guid;
    std::stringstream ss(hexString);
    ss >> std::hex >> guid.Data1 >> guid.Data2 >> guid.Data3 >> guid.Data4[0] >> guid.Data4[1] >> guid.Data4[2] >> guid.Data4[3] >> guid.Data4[4] >> guid.Data4[5] >> guid.Data4[6] >> guid.Data4[7];

    // Return the converted GUID structure
    return guid;
}
