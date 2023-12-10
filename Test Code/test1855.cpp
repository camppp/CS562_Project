vector<int> processCards(string line) {
    vector<int> queens(4, 0);
    vector<int> jacks(4, 0);
    vector<bool> stop(4, false);

    for (int i = 0; i < line.length(); i += 3) {
        char rank = line[i];
        char suit = line[i + 1];

        if (rank == 'A') {
            queens[suit - 'S']++;
        } else if (rank == 'J') {
            jacks[suit - 'S']++;
        } else if (rank == 'T') {
            stop[suit - 'S'] = true;
        }
    }

    return {queens, jacks, stop};
}
