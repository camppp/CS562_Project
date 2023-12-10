#include <iostream>
#include <unordered_map>
#include <string>

class LitstrTable {
private:
    std::unordered_map<int, std::string> litstrMap;

    LitstrTable() {}  // Private constructor to enforce singleton pattern

public:
    static LitstrTable& get() {
        static LitstrTable instance;
        return instance;
    }

    void setLitstr(int id, const std::string& ret) {
        litstrMap[id] = ret;
    }

    const std::string& getLitstr(int id) {
        return litstrMap[id];
    }
};

int main() {
    LitstrTable::get().setLitstr(1, "Hello");
    LitstrTable::get().setLitstr(2, "World");

    std::cout << LitstrTable::get().getLitstr(1) << " " << LitstrTable::get().getLitstr(2) << std::endl;

    return 0;
}
