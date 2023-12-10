#include <cstdint>

namespace game {
    struct ItemID {
        // Define ItemID structure as per game requirements
    };

    class AmmoData {
    public:
        AmmoData(ItemID id, int32_t available, int32_t equipped)
            : id(id), available(available), equipped(equipped) {}

        // Getter and setter methods for id, available, and equipped
        ItemID getId() const { return id; }
        void setId(ItemID newId) { id = newId; }

        int32_t getAvailable() const { return available; }
        void setAvailable(int32_t newAvailable) { available = newAvailable; }

        int32_t getEquipped() const { return equipped; }
        void setEquipped(int32_t newEquipped) { equipped = newEquipped; }

        // Method to check if ammunition is available
        bool isAmmoAvailable() const {
            return available > 0;
        }

        // Method to equip ammunition
        void equipAmmo(int32_t amount) {
            if (amount <= available) {
                equipped += amount;
                available -= amount;
            }
        }

    private:
        ItemID id;
        int32_t available;
        int32_t equipped;
    };

    static_assert(sizeof(AmmoData) == 0x18, "AmmoData size mismatch");
} // namespace game
