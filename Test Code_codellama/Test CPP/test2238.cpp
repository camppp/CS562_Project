int getBinCount(const int &binIndex) {
    if (binIndex >= 0 && binIndex < nbins) {
        return bins[binIndex];
    }
    return 0;
}
