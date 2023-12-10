#include <iostream>
#include <vector>
#include <algorithm>

class Sandwich {
private:
    std::vector<std::string> ingredients;

public:
    void AddIngredient(const std::string& ingredient) {
        ingredients.push_back(ingredient);
    }

    void RemoveIngredient(const std::string& ingredient) {
        ingredients.erase(std::remove(ingredients.begin(), ingredients.end(), ingredient), ingredients.end());
    }

    std::vector<std::string> GetIngredients() {
        return ingredients;
    }
};

int main() {
    Sandwich s;
    s.AddIngredient("Turkey");
    s.AddIngredient("Cheddar");
    s.AddIngredient("Lettuce");
    s.AddIngredient("Tomato");
    s.AddIngredient("Mayo");
    s.RemoveIngredient("Cheddar");

    std::vector<std::string> currentIngredients = s.GetIngredients();
    std::cout << "Current Ingredients: ";
    for (const auto& ingredient : currentIngredients) {
        std::cout << ingredient << " ";
    }
    std::cout << std::endl;

    return 0;
}
