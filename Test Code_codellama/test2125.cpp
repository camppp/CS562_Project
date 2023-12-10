class CustomString {
private:
    std::string str;

public:
    CustomString(const std::string& s) : str(s) {}

    CustomString operator+(const std::string& suffix) {
        return CustomString(str + suffix);
    }

    size_t length() const {
        return str.length();
    }

    void print() const {
        std::cout << str << std::endl;
    }
};
