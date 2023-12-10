#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Define the loot distribution data
vector<LootDistribution> loot_distribution_data = {
    {"Loot_VEHICLE", 1, "WeaponHolder_ItemHatchet"},
    {"Loot_GROUP", 5, "shotgunsingleshot"},
    {"Loot_GROUP", 4, "backpacks"},
    {"Loot_MAGAZINE", 4, "ItemSandbag"},
    {"Loot_MAGAZINE", 2, "equip_Crossbow_Kit"},
    {"Loot_MAGAZINE", 2, "equip_crossbow_stock"},
    {"Loot_MAGAZINE", 2, "ItemComboLock"},
    {"Loot_MAGAZINE", 1, "equip_tent_poles"}
};

// Define the function to generate loot
vector<string> generate_loot(vector<LootDistribution> loot_distribution_data) {
    // Initialize the output vector
    vector<string> loot;

    // Loop through the loot distribution data
    for (int i = 0; i < loot_distribution_data.size(); i++) {
        // Get the current loot distribution
        LootDistribution dist = loot_distribution_data[i];

        // Generate a random number between 0 and the weight of the current loot distribution
        int random_number = rand() % dist.weight;

        // If the random number is less than or equal to the weight of the current loot distribution, add the item to the output vector
        if (random_number <= dist.weight) {
            loot.push_back(dist.item);
        }
    }

    // Return the output vector
    return loot;
}

int main() {
    // Call the generate_loot function and print the output
    vector<string> loot = generate_loot(loot_distribution_data);
    for (int i = 0; i < loot.size(); i++) {
        cout << loot[i] << endl;
    }

    return 0;
}
