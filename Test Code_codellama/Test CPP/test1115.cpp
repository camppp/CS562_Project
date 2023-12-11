#include <cstdint>

namespace game {

struct AmmoData {
    ItemID id;
    int32_t available;
    int32_t equipped;
};

class AmmoData {
public:
    AmmoData(ItemID id, int32_t available, int32_t equipped) : id(id), available(available), equipped(equipped) {}

    ItemID getId() const { return id; }
    void setId(ItemID id) { this->id = id; }

    int32_t getAvailable() const { return available; }
    void setAvailable(int32_t available) { this->available = available; }

    int32_t getEquipped() const { return equipped; }
    void setEquipped(int32_t equipped) { this->equipped = equipped; }

    bool isAvailable() const { return available > 0; }

    void equip() { equipped = available; available = 0; }
};

} // namespace game
