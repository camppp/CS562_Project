#include <iostream>

class Card {
    // Details of the Card class are not provided
};

class Hands {
private:
    Card* hand[10];  // Assuming a maximum of 10 cards in the hand

public:
    Hands() {
        for (int i = 0; i < 10; i++) {
            hand[i] = nullptr;  // Initialize all elements to nullptr
        }
    }

    // Set a card at the specified position in the hand
    void setCard(int n, Card* card) {
        if (n < 0 || n >= 10) {
            std::cout << "Invalid position. Position should be between 0 and 9." << std::endl;
            return;
        }

        if (hand[n] != nullptr) {
            delete hand[n];  // Release memory if a card already exists at the position
        }

        hand[n] = card;  // Set the card at the specified position
    }

    // Destructor to release memory for all cards in the hand
    ~Hands() {
        for (int i = 0; i < 10; i++) {
            if (hand[i] != nullptr) {
                delete hand[i];
            }
        }
    }
};

int main() {
    // Example usage
    Hands playerHand;
    Card* newCard = new Card();  // Create a new card object
    playerHand.setCard(2, newCard);  // Set the new card at position 2 in the hand

    return 0;
}
