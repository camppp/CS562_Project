class MedicalDetection {
private:
    double vitalSigns[3]; // array to store the last three vital sign measurements
    double threshold; // threshold for detecting an issue

public:
    MedicalDetection(double threshold) {
        this->threshold = threshold;
    }

    void addVitalSign(double vitalSign) {
        // shift the array of vital signs by one position
        for (int i = 0; i < 2; i++) {
            vitalSigns[i] = vitalSigns[i + 1];
        }
        // add the new vital sign to the end of the array
        vitalSigns[2] = vitalSign;
    }

    bool detectIssue() {
        // check if any of the last three vital signs are outside the normal range
        for (int i = 0; i < 3; i++) {
            if (vitalSigns[i] < 60 || vitalSigns[i] > 100) {
                return true;
            }
        }

        // check if the difference between two consecutive vital signs exceeds the threshold
        if (vitalSigns[2] - vitalSigns[1] > threshold) {
            return true;
        }

        return false;
    }
};
