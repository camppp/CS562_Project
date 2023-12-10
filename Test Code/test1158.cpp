int calculateTotalUsedRecHits(const std::vector<RecHit>& forwardRecHits, const std::vector<RecHit>& backwardRecHits) {
    int totalUsedRecHits = 0;
    
    for (const RecHit& recHit : forwardRecHits) {
        if (recHit.isValid() && recHit.isUsed()) {
            totalUsedRecHits++;
        }
    }
    
    for (const RecHit& recHit : backwardRecHits) {
        if (recHit.isValid() && recHit.isUsed()) {
            totalUsedRecHits++;
        }
    }
    
    return totalUsedRecHits;
}
