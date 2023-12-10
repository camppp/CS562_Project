#include <iostream>

class DasManager {
private:
    int das_full_charge_;
    int das_min_charge_;

public:
    // Constructor to initialize the DAS counter
    DasManager(int full_charge, int min_charge) : das_full_charge_(full_charge), das_min_charge_(min_charge) {}

    // Method to fully charge the DAS counter
    void fullyChargeDas(int& das_counter) const { das_counter = das_full_charge_; }

    // Method to softly reset the DAS counter
    void softResetDas(int& das_counter) const { das_counter = das_min_charge_; }

    // Method to hard reset the DAS counter
    void hardResetDas(int& das_counter) const { das_counter = 0; }

    // Method to check if the DAS counter is fully charged
    bool dasFullyCharged(const int das_counter) const {
        return das_counter >= das_full_charge_;
    }

    // Method to check if the DAS counter is softly charged
    bool dasSoftlyCharged(const int das_counter) const {
        return das_counter >= das_min_charge_;
    }
};

int main() {
    // Example usage of the DasManager class
    DasManager das_manager(10, 3);  // Initialize DAS counter with full charge 10 and minimum charge 3
    int das_counter = 0;

    das_manager.fullyChargeDas(das_counter);
    std::cout << "DAS fully charged: " << das_manager.dasFullyCharged(das_counter) << std::endl;

    das_manager.softResetDas(das_counter);
    std::cout << "DAS softly charged: " << das_manager.dasSoftlyCharged(das_counter) << std::endl;

    das_manager.hardResetDas(das_counter);
    std::cout << "DAS fully charged: " << das_manager.dasFullyCharged(das_counter) << std::endl;

    return 0;
}
