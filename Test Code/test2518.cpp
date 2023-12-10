class PeakTracker {
private:
    int m_track_peak;

public:
    PeakTracker() : m_track_peak(0) {}

    bool is_track_peak_present() {
        return m_track_peak != 0;
    }

    void update_peak(int peak_value) {
        m_track_peak = peak_value;
    }
};
