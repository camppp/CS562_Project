#include <cassert>
#include <string>

class XMLIterPrinter {
private:
    bool theOpenStart;

public:
    XMLIterPrinter() : theOpenStart(true) {}

    void addStrAttribute(const char* name, const char* value) {
        assert(theOpenStart);
        assert(name != nullptr && value != nullptr);
        std::string attr = std::string(name) + "=\"" + value + "\"";
        // Add the attribute to the XML element being constructed
        // ...
        theOpenStart = false;
    }

    void addIntAttribute(const char* name, xs_integer value) {
        assert(theOpenStart);
        assert(name != nullptr);
        std::string attr = std::string(name) + "=\"" + std::to_string(value) + "\"";
        // Add the attribute to the XML element being constructed
        // ...
        theOpenStart = false;
    }

    void addDecAttribute(const char* name, double value) {
        assert(theOpenStart);
        assert(name != nullptr);
        std::string attr = std::string(name) + "=\"" + std::to_string(value) + "\"";
        // Add the attribute to the XML element being constructed
        // ...
        theOpenStart = false;
    }
};
