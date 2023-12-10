#include <iostream>
#include <fstream>
#include <stack>
#include <string>

struct Carte {
    // Define the structure for a playing card
    // (e.g., suit, value, etc.)
};

class Deck {
private:
    std::stack<Carte> cardStack;
    int size;

public:
    // Constructor to initialize the deck with cards from a file
    Deck(std::string fichier) {
        // Read the file and initialize the cardStack with the cards
        std::ifstream file(fichier);
        if (file.is_open()) {
            // Read the file and populate the cardStack
            // Example: while (file >> suit >> value) { cardStack.push({suit, value}); }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file" << std::endl;
        }
    }

    // Destructor to clean up any resources used by the deck
    ~Deck() {
        // Perform any necessary cleanup
    }

    // Getter to retrieve the size of the deck
    int getTaille() {
        return size;
    }

    // Setter to set the size of the deck
    void setTaille(int t) {
        size = t;
    }

    // Getter to retrieve the stack of cards in the deck
    std::stack<Carte> getStack() {
        return cardStack;
    }
};

int main() {
    // Example usage of the Deck class
    Deck myDeck("cards.txt");
    std::stack<Carte> cards = myDeck.getStack();
    // Perform operations with the deck
    return 0;
}
