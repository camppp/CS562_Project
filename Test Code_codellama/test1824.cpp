class UVAArenaSettings {
private:
    SettingsManager settings;
    const string KeyProblemsUpdateInterval = "problems_update_interval";
    const string KeyMaxProblemsTableRowsToFetch = "max_problems_table_rows_to_fetch";
    const int DefaultMaxProblemsTableRowsToFetch = 100;

public:
    UVAArenaSettings() {}

    void setProblemsUpdateInterval(int interval) {
        settings.set(KeyProblemsUpdateInterval, interval);
    }

    int getProblemsUpdateInterval() {
        return settings.get(KeyProblemsUpdateInterval, DefaultProblemsUpdateInterval);
    }

    void setMaxProblemsTableRowsToFetch(int numRows) {
        settings.set(KeyMaxProblemsTableRowsToFetch, numRows);
    }

    int getMaxProblemsTableRowsToFetch() {
        return settings.get(KeyMaxProblemsTableRowsToFetch, DefaultMaxProblemsTableRowsToFetch);
    }
};
