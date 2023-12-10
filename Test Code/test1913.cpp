#include <iostream>
#include <sstream>

class Stream {
private:
    std::stringstream ss_;

    void checkedNext(Stream& stream) {
        // Perform validation logic here
        // For example, check if the stream is in a valid state
        // This is a placeholder for actual validation logic
        std::cout << "Performing validation before pushing data onto the stream" << std::endl;
    }

public:
    Stream& push(long s) {
        checkedNext(*this);
        ss_ << s;
        return *this;
    }

    Stream& push(int s) {
        checkedNext(*this);
        ss_ << s;
        return *this;
    }

    Stream& push(double s) {
        checkedNext(*this);
        ss_ << s;
        return *this;
    }

    Stream& push(const std::string& s) {
        checkedNext(*this);
        ss_ << s;
        return *this;
    }

    std::string str() const {
        return ss_.str();
    }
};

int main() {
    Stream stream;
    stream.push(10).push(20.5).push("Hello, ").push(30);
    std::cout << stream.str() << std::endl;
    return 0;
}
