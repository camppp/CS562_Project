class iPhone : public Nokia {
public:
    void Call(const std::string& number) override {
        std::cout << "Calling " << number << " using iPhone" << std::endl;
    }
};

class iPhoneFactory : public Factory {
public:
    Nokia* CreateNokia() override {
        return new iPhone();
    }
};
