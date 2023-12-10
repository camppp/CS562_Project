#include <iostream>
#include <string>
#include <vector>

class XMLDoc {
private:
    int ID;
    std::vector<std::pair<int, std::string>> children;

public:
    XMLDoc(int id) : ID(id) {}

    void newChild(int opnum, std::string CDATA) {
        children.push_back(std::make_pair(opnum, CDATA));
    }

    void display() {
        std::cout << "<XMLDoc ID=" << ID << ">" << std::endl;
        for (const auto& child : children) {
            std::cout << "  <Child opnum=" << child.first << ">" << child.second << "</Child>" << std::endl;
        }
        std::cout << "</XMLDoc>" << std::endl;
    }
};

class XMLManager {
public:
    XMLDoc* newXMLDoc(int opnum, std::string CDATA) {
        XMLDoc* doc = new XMLDoc(0);
        doc->newChild(opnum, CDATA);
        return doc;
    }
};

int main() {
    XMLManager manager;
    XMLDoc* doc = manager.newXMLDoc(1, "Sample CDATA");
    doc->display();
    delete doc;  // Remember to free the memory allocated for the XMLDoc object
    return 0;
}
