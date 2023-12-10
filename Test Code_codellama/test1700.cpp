#include <iostream>
#include <string>
#include <tinyxml.h>

class DimensionsManager {
public:
    DimensionsManager() : height(0), width(0), depth(0) {}

    void setHeight(int h) { height = h; }
    void setWidth(int w) { width = w; }
    void setDepth(int d) { depth = d; }

    int getHeight() const { return height; }
    int getWidth() const { return width; }
    int getDepth() const { return depth; }

    void serialize(TiXmlElement* element) const {
        element->SetAttribute("V", width);
        element->SetAttribute("H", height);
        element->SetAttribute("D", depth);
    }

private:
    int height;
    int width;
    int depth;
};

int main() {
    DimensionsManager dimensions;
    dimensions.setHeight(10);
    dimensions.setWidth(20);
    dimensions.setDepth(30);

    TiXmlElement* element = new TiXmlElement("Dimensions");
    dimensions.serialize(element);

    std::cout << element->GetAttribute("V") << std::endl;
    std::cout << element->GetAttribute("H") << std::endl;
    std::cout << element->GetAttribute("D") << std::endl;

    delete element;

    return 0;
}
