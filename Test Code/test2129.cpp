class OutstationStatistics {
public:
    OutstationStatistics() {
        // Initialize the statistics to 0
        for (int i = 0; i < statistics_count; i++) {
            statistics[i] = 0;
        }
    }

    bool pollAPDU() {
        // Check if there is a pending APDU to be processed
        if (pending_apdu) {
            return true;
        } else {
            return false;
        }
    }

    int getStatistic(Statistics stat) {
        // Return the value of the corresponding statistic
        return statistics[stat];
    }

private:
    int statistics[statistics_count];
    bool pending_apdu;
};
