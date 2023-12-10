#include <iostream>
#include <string>

class Nokia {
public:
    virtual void Call(const std::string& number) = 0;
};

class Lumia920 : public Nokia {
public:
    void Call(const std::string& number) override {
        std::cout << "Calling " << number << " using Lumia920" << std::endl;
    }
};

class iPhone : public Nokia {
public:
    void Call(const std::string& number) override {
        std::cout << "Calling " << number << " using iPhone" << std::endl;
    }
};

class Factory {
public:
    virtual Nokia* CreateNokia() = 0;
};

class Lumia920Factory : public Factory {
public:
    Nokia* CreateNokia() override {
        return new Lumia920();
    }
};

class iPhoneFactory : public Factory {
public:
    Nokia* CreateNokia() override {
        return new iPhone();
    }
};

int main(void) {
    Factory* pFactory = new Lumia920Factory();
    Nokia* pNokia = pFactory->CreateNokia();
    pNokia->Call("12345680");

    delete pNokia;
    delete pFactory;

    pFactory = new iPhoneFactory();
    pNokia = pFactory->CreateNokia();
    pNokia->Call("12345680");

    delete pNokia;
    delete pFactory;

    return 0;
}
