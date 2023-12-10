#include <iostream>

class SoulRandAttrConfig {
public:
    SoulRandAttrConfig() : attr_type(0), attr_val(0) {}

    void setAttrType(int type) { attr_type = type; }
    void setAttrVal(int val) { attr_val = val; }

    int getAttrType() { return attr_type; }
    int getAttrVal() { return attr_val; }

    void display() {
        std::cout << "Attribute type: " << attr_type << std::endl;
        std::cout << "Attribute value: " << attr_val << std::endl;
    }

private:
    int attr_type;
    int attr_val;
};

int main() {
    SoulRandAttrConfig config;

    config.setAttrType(1);
    config.setAttrVal(10);

    config.display();

    return 0;
}
