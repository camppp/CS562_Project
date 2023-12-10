#include <iostream>

class SoulRandAttrConfig {
private:
    int attr_type;
    int attr_val;

public:
    SoulRandAttrConfig() : attr_type(0), attr_val(0) {}

    void setAttrType(int type) {
        attr_type = type;
    }

    void setAttrValue(int value) {
        attr_val = value;
    }

    int getAttrType() const {
        return attr_type;
    }

    int getAttrValue() const {
        return attr_val;
    }

    void displayConfig() const {
        std::cout << "Attribute Type: " << attr_type << ", Attribute Value: " << attr_val << std::endl;
    }
};

int main() {
    SoulRandAttrConfig config1;
    config1.setAttrType(1);
    config1.setAttrValue(100);
    config1.displayConfig();

    SoulRandAttrConfig config2;
    config2.setAttrType(2);
    config2.setAttrValue(75);
    config2.displayConfig();

    return 0;
}
