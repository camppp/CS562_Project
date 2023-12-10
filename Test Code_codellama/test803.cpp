#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Deck {
public:
    Deck(const std::string& filename) {
        // Open the file and read the cards
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            cards.push_back(line);
        }
    }

    ~Deck() {
        // Clean up the resources used by the deck
        cards.clear();
    }

    int size() const {
        return cards.size();
    }

    void setSize(int size) {
        cards.resize(size);
    }

    std::vector<std::string> getCards() const {
        return cards;
    }

private:
    std::vector<std::string> cards;
};
