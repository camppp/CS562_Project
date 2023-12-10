#include <string>
#include <unordered_map>

namespace SoapySDR
{
    /*!
     * Convert a error code to a string for printing purposes.
     * 
     * @param errorCode the error code to convert to a string
     * @return a string representation of the error code
     */
    std::string errorCodeToString(int errorCode)
    {
        // Define a map to store error code to string mappings
        static const std::unordered_map<int, std::string> errorMap = {
            {0, "No error"},
            {1, "Invalid argument"},
            {2, "Device not found"},
            // Add more error code to string mappings as needed
        };

        // Check if the error code exists in the map
        auto it = errorMap.find(errorCode);
        if (it != errorMap.end())
        {
            return it->second; // Return the corresponding string representation
        }
        else
        {
            return "Unknown error"; // Return a default string for unknown error codes
        }
    }
}
