size_t calculateTotalBytesSent(const ssize_t* reportSizes, size_t numReports) {
    size_t totalBytesSent = 0;
    for (size_t i = 0; i < numReports; i++) {
        if (reportSizes[i] > 0) {
            totalBytesSent += reportSizes[i];
        }
    }
    return totalBytesSent;
}
