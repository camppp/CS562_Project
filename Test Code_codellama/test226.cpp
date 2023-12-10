void processTransaction() {
    static uint32_t txns_processed = 0;

    // Increment the transaction count
    txns_processed++;

    // Check for overflow
    if (txns_processed == UINT32_MAX) {
        // Wrap around to 0
        txns_processed = 0;
    }
}
