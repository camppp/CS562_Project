#include <iostream>
#include <map>

class Roman_int {
public:
    enum RomanNumeral { I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 };

    Roman_int(RomanNumeral numeral = I) : value(numeral) {}

    int as_int() const {
        return static_cast<int>(value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Roman_int& r) {
        static const std::map<RomanNumeral, std::string> roman_map = {
            {I, "I"}, {V, "V"}, {X, "X"}, {L, "L"}, {C, "C"}, {D, "D"}, {M, "M"}
        };
        os << "Roman " << roman_map.at(r.value) << " equals " << r.as_int() << " ";
        return os;
    }

private:
    RomanNumeral value;
};

int main() {
    Roman_int r(Roman_int::V);
    std::cout << r << std::endl;

    Roman_int rr;
    std::cout << rr << std::endl;

    return 0;
}
