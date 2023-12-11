class SetPeakMetadata {
private:
    SpectrumInfo& spectrumInfo;
    std::map<int, PeakMetadata> peakMetadataMap;

public:
    SetPeakMetadata(SpectrumInfo& _spectrumInfo) : spectrumInfo(_spectrumInfo) {}

    void addPeakMetadata(const PeakMetadata& metadata) {
        peakMetadataMap[metadata.peakIndex] = metadata;
    }

    const PeakMetadata& getPeakMetadata(int peakIndex) const {
        return peakMetadataMap.at(peakIndex);
    }

    void updatePeakMetadata(int peakIndex, const PeakMetadata& metadata) {
        peakMetadataMap[peakIndex] = metadata;
    }

    void removePeakMetadata(int peakIndex) {
        peakMetadataMap.erase(peakIndex);
    }
};
