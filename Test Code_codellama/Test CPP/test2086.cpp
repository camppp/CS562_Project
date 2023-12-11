#include <vector>

class coils : public mb_datas {
public:
    coils() {}
    coils(std::initializer_list<coil> coils) : mb_datas(coils) {}

    void fill_address(uint16_t address) {
        for (auto& coil : mb_datas) {
            coil.address = address;
        }
    }

    void remove_fill_data(uint16_t quantity) {
        for (auto& coil : mb_datas) {
            coil.data.erase(coil.data.begin(), coil.data.begin() + quantity);
        }
    }

    bool operator==(const coil& other) const {
        return address == other.address && data == other.data;
    }

private:
    std::vector<coil> mb_datas;
};
