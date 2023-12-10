class MasaNetStatus {
    // Define the MasaNetStatus class members and methods
};

class CmdStatusResponse {
    MasaNetStatus status;

public:
    const MasaNetStatus& getStatus() const {
        return status;
    }

    void updateStatus(const MasaNetStatus& newStatus) {
        status = newStatus;
    }
};
