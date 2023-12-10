#include <iostream>
#include "tinyxml.h"

class DimensionsManager {
private:
    double height;
    double width;
    double depth;

public:
    DimensionsManager(double h = 0.0, double w = 0.0, double d = 0.0) : height(h), width(w), depth(d) {}

    void setHeight(double h) {
        height = h;
    }

    void setWidth(double w) {
        width = w;
    }

    void setDepth(double d) {
        depth = d;
    }

    double getHeight() const {
        return height;
    }

    double getWidth() const {
        return width;
    }

    double getDepth() const {
        return depth;
    }

    void serializeToXML() const {
        TiXmlDocument doc;
        TiXmlElement* root = new TiXmlElement("dimensions");
        root->SetDoubleAttribute("V", width);
        root->SetDoubleAttribute("H", height);
        root->SetDoubleAttribute("D", depth);

        TiXmlElement* pelem = new TiXmlElement("dimensions");
        pelem->SetAttribute("DIM_V", width);

        doc.LinkEndChild(root);
        root->LinkEndChild(pelem);

        doc.SaveFile("dimensions.xml");
    }
};

int main() {
    DimensionsManager manager(10.0, 5.0, 8.0);
    manager.serializeToXML();
    return 0;
}
