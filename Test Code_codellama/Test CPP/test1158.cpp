int calculateTotalUsedRecHits(const std::vector<RecHit>& forwardRecHits, const std::vector<RecHit>& backwardRecHits) {
    int totalUsedRecHits = 0;
    for (const auto& forwardRecHit : forwardRecHits) {
        if (forwardRecHit.isUsed() && forwardRecHit.isValid()) {
            totalUsedRecHits++;
        }
    }
    for (const auto& backwardRecHit : backwardRecHits) {
        if (backwardRecHit.isUsed() && backwardRecHit.isValid()) {
            totalUsedRecHits++;
        }
    }
    return totalUsedRecHits;
}
