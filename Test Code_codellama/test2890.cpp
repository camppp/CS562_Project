#include <iostream>
#include <string>

class XMLDoc {
public:
    int id;
    std::string cdata;

    XMLDoc(int id, std::string cdata) : id(id), cdata(cdata) {}

    void newChild(int opnum, std::string cdata) {
        // Add a new child element to the XML document with the given operation number and character data
        // ...
    }
};

class XMLManager {
public:
    XMLDoc newXMLDoc(int opnum, std::string cdata) {
        // Create a new XML document with the given operation number and character data
        XMLDoc doc(0, cdata);
        doc.newChild(opnum, cdata);
        return doc;
    }
};
