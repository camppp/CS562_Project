double calculateMSE(const QVector<double>& set1, const QVector<double>& set2) {
    if (set1.size() != set2.size()) {
        // Handle error: sets must be of equal size
        return -1.0; // or throw an exception
    }

    double sumSquaredDiff = 0.0;
    for (int i = 0; i < set1.size(); i++) {
        double diff = set1[i] - set2[i];
        sumSquaredDiff += diff * diff;
    }

    return sumSquaredDiff / set1.size();
}
