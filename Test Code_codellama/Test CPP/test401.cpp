#include <iostream>
#include <string>
#include <vector>

class Sandwich {
public:
    void AddIngredient(const std::string& ingredient) {
        ingredients.push_back(ingredient);
    }

    void RemoveIngredient(const std::string& ingredient) {
        auto it = std::find(ingredients.begin(), ingredients.end(), ingredient);
        if (it != ingredients.end()) {
            ingredients.erase(it);
        }
    }

    std::vector<std::string> GetIngredients() const {
        return ingredients;
    }

private:
    std::vector<std::string> ingredients;
};

int main() {
    Sandwich sandwich;

    sandwich.AddIngredient("Bread");
    sandwich.AddIngredient("Meat");
    sandwich.AddIngredient("Cheese");

    std::cout << "Current ingredients: ";
    for (const auto& ingredient : sandwich.GetIngredients()) {
        std::cout << ingredient << " ";
    }
    std::cout << std::endl;

    sandwich.RemoveIngredient("Meat");

    std::cout << "Current ingredients: ";
    for (const auto& ingredient : sandwich.GetIngredients()) {
        std::cout << ingredient << " ";
    }
    std::cout << std::endl;

    return 0;
}
