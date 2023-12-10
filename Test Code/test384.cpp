void shuffleDeck(std::vector<Card>& deck) {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = deck.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        std::swap(deck[i], deck[j]);
    }
}
