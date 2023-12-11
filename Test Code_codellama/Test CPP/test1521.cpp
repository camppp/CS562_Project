std::pair<int, int> findMinMaxHitIndices(const std::vector<Hit>& hits) {
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < hits.size(); i++) {
        if (hits[i].time < hits[minIndex].time) {
            minIndex = i;
        }
        if (hits[i].time > hits[maxIndex].time) {
            maxIndex = i;
        }
    }

    return {minIndex, maxIndex};
}
