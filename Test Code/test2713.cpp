#include <iostream>
#include <string>

class MeiAttribute {
public:
    MeiAttribute(std::string name, std::string value) : name(name), value(value) {}
    std::string getName() { return name; }
    std::string getValue() { return value; }
private:
    std::string name;
    std::string value;
};

class FingGrpVisMixIn {
public:
    void setOrient(std::string _orient) {
        MeiAttribute *a = new MeiAttribute("orient", _orient);
        b->addAttribute(a);
    }

    bool hasOrient() {
        return b->hasAttribute("orient");
    }

    std::string getOrient() {
        if (hasOrient()) {
            return b->getAttribute("orient")->getValue();
        } else {
            return "";
        }
    }

private:
    // Assume the existence of a class member 'b' representing the fingering group
    // and its associated methods addAttribute, hasAttribute, and getAttribute
};
