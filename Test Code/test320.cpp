class Hands {
public:
    // Set a card at the specified position in the hand
    void setCard(int n, Card* card) {
        if (n < 0 || n >= handSize) {
            throw std::out_of_range("Position out of bounds");
        }
        hand[n] = card;
    }

private:
    int handSize;
    Card* hand[];
};
