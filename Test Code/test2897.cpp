#include <unordered_map>
#include <string>

class StringManager {
private:
    std::unordered_map<tCIDLib::TCard4, std::string> idToStringMap;
    std::unordered_map<std::string, tCIDLib::TCard4> stringToIdMap;
    tCIDLib::TCard4 nextId = 1;

public:
    // Add a new string with a unique ID
    void addString(const std::string& strMoniker) {
        idToStringMap[nextId] = strMoniker;
        stringToIdMap[strMoniker] = nextId;
        nextId++;
    }

    // Retrieve a string by its ID
    std::string getStringById(tCIDLib::TCard4 c4Id) {
        if (idToStringMap.count(c4Id) > 0) {
            return idToStringMap[c4Id];
        }
        return "";  // Return empty string if ID not found
    }

    // Remove a string by its ID
    void removeStringById(tCIDLib::TCard4 c4Id) {
        if (idToStringMap.count(c4Id) > 0) {
            stringToIdMap.erase(idToStringMap[c4Id]);
            idToStringMap.erase(c4Id);
        }
    }

    // Retrieve the ID of a given string
    tCIDLib::TCard4 getIdByString(const std::string& strMoniker) {
        if (stringToIdMap.count(strMoniker) > 0) {
            return stringToIdMap[strMoniker];
        }
        return 0;  // Return 0 if string not found
    }
};
