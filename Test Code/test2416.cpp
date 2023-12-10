#include <iostream>
#include <string>

class Reference {
private:
    int referenceCount;
    std::string* referredObject;

public:
    Reference(std::string* obj) : referenceCount(1), referredObject(obj) {}

    void grabReference() {
        referenceCount++;
    }

    void releaseReference() {
        referenceCount--;
        if (referenceCount == 0) {
            delete referredObject;
            delete this;
        }
    }

    ~Reference() {
        delete referredObject;
    }
};

int main() {
    std::string* str = new std::string("Hello, World!");
    Reference* ref = new Reference(str);

    ref->grabReference();
    ref->grabReference();
    ref->releaseReference();
    ref->releaseReference(); // Object should be released here

    return 0;
}
