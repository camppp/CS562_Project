class LiquidContainer {
private:
    double startVol;
    double endVol;
    bool firstVol;

public:
    LiquidContainer() {
        startVol = 0;
        endVol = 0;
        firstVol = false;
    }

    void fill(double volume) {
        if (firstVol) {
            return "Container already filled";
        }
        startVol = volume;
        firstVol = true;
    }

    void empty() {
        endVol = startVol;
        startVol = 0;
    }

    double getCurrentVolume() {
        return startVol;
    }
};
