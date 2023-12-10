#include <iostream>
#include <string>

class XML_Typedef {
public:
    class HELPER {
    public:
        void parseXML(const std::string& xmlData) {
            // Implementation for parsing XML data
            std::cout << "Parsing XML data: " << xmlData << std::endl;
        }

        std::string extractValue(const std::string& tag) {
            // Implementation for extracting value from XML tag
            return "Value extracted from tag: " + tag;
        }
    };

    static HELPER XML_HELPER;
};

// Initialize the static instance of HELPER within XML_Typedef
XML_Typedef::HELPER XML_Typedef::XML_HELPER;

int main() {
    // Example usage
    std::string xmlData = "<book><title>Sample Title</title><author>Sample Author</author></book>";
    XML_Typedef::XML_HELPER.parseXML(xmlData);
    std::string extractedValue = XML_Typedef::XML_HELPER.extractValue("title");
    std::cout << extractedValue << std::endl;

    return 0;
}
