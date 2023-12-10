#include <iostream>
#include "XMLParser.h" // Include the header file for XMLParser

class XMLParser : public abstract_delegate {
public:
  void onStartElement(const XML_Char *fullname, const XML_Char **atts) override {
    // Implement the logic to handle the start element event
    std::cout << "Start Element: " << fullname << std::endl;
    // Process the attributes if needed
    if (atts != nullptr) {
        for (int i = 0; atts[i]; i += 2) {
            std::cout << "Attribute: " << atts[i] << " = " << atts[i + 1] << std::endl;
        }
    }
  }

  void onEndElement(const XML_Char *fullname) override {
    // Implement the logic to handle the end element event
    std::cout << "End Element: " << fullname << std::endl;
  }

  void onCharacterData(const char *pBuf, int len) override {
    // Implement the logic to handle the character data event
    std::cout << "Character Data: " << std::string(pBuf, len) << std::endl;
  }

  void onProcessingInstruction(const XML_Char *target, const XML_Char *data) override {
    // Implement the logic to handle the processing instruction event
    std::cout << "Processing Instruction: " << target << " " << data << std::endl;
  }

  void onUnparsedEntityDecl(const XML_Char *entityName, const XML_Char *base, const XML_Char *systemId) override {
    // Implement the logic to handle the unparsed entity declaration event
    std::cout << "Unparsed Entity Declaration: " << entityName << " " << base << " " << systemId << std::endl;
  }
};

int main() {
  // Create an instance of XMLParser
  XMLParser parser;

  // Simulate XML events to test the parser
  const XML_Char *fullname = "element";
  const XML_Char *atts[] = { "attr1", "value1", "attr2", "value2", nullptr };
  parser.onStartElement(fullname, atts);

  parser.onCharacterData("Sample character data", 19);

  parser.onProcessingInstruction("target", "data");

  parser.onUnparsedEntityDecl("entity", "base", "systemId");

  parser.onEndElement("element");

  return 0;
}
