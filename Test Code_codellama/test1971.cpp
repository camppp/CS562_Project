double calculateMSE(const QVector<double>& set1, const QVector<double>& set2) {
    double mse = 0.0;
    for (int i = 0; i < set1.size(); i++) {
        double diff = set1[i] - set2[i];
        mse += diff * diff;
    }
    return mse / set1.size();
}
