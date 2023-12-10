#include <iostream>
#include <map>

class MetaObject {
public:
    MetaObject() {}

    void registerMetaObject(const std::string& className, const std::string& metaObject) {
        metaObjects[className] = metaObject;
    }

    std::string getMetaObject(const std::string& className) {
        return metaObjects[className];
    }

private:
    std::map<std::string, std::string> metaObjects;
};

class SimpleMissionItem {
public:
    SimpleMissionItem() {}

    void registerMetaObject() {
        MetaObject::registerMetaObject("SimpleMissionItem", "staticMetaObject");
    }

    std::string getMetaObject() {
        return MetaObject::getMetaObject("SimpleMissionItem");
    }
};

int main() {
    SimpleMissionItem item;
    item.registerMetaObject();
    std::cout << item.getMetaObject() << std::endl;
    return 0;
}
