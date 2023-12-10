class UVAArenaSettings {
private:
    QSettings settings; // Assuming QSettings is used for settings management
    const QString KeyProblemsUpdateInterval = "ProblemsUpdateInterval";
    const QString KeyMaxProblemsTableRowsToFetch = "MaxProblemsTableRowsToFetch";
    const qint32 DefaultMaxProblemsTableRowsToFetch = 100; // Example default value

public:
    void setProblemsUpdateInterval(qint32 days) {
        settings.setValue(KeyProblemsUpdateInterval, days);
    }

    qint32 maxProblemsTableRowsToFetch() {
        return settings.value(KeyMaxProblemsTableRowsToFetch, DefaultMaxProblemsTableRowsToFetch).toInt();
    }

    void setMaxProblemsTableRowsToFetch(qint32 numRows) {
        settings.setValue(KeyMaxProblemsTableRowsToFetch, numRows);
    }
};
