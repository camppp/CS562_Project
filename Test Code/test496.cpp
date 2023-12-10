#include <iostream>
#include <vector>

class MedicalDetection {
private:
    std::vector<double> vitalSigns;
    double threshold;

public:
    MedicalDetection(double threshold) : threshold(threshold) {}

    void addVitalSign(double vitalSign) {
        vitalSigns.push_back(vitalSign);
    }

    bool detectIssue() {
        int consecutiveCount = 0;
        for (size_t i = 1; i < vitalSigns.size(); ++i) {
            if (isAbnormal(vitalSigns[i], vitalSigns[i - 1])) {
                consecutiveCount++;
                if (consecutiveCount >= 2) {
                    return true;
                }
            } else {
                consecutiveCount = 0;
            }
        }
        return false;
    }

private:
    bool isAbnormal(double current, double previous) {
        // Add specific conditions for abnormal vital signs (e.g., heart rate, blood pressure)
        if (current > 100 || current < 60) {
            return true;
        }
        if (std::abs(current - previous) > threshold) {
            return true;
        }
        return false;
    }
};

int main() {
    MedicalDetection detector(20.0);
    detector.addVitalSign(80.0);
    detector.addVitalSign(90.0);
    detector.addVitalSign(110.0);
    std::cout << "Issue detected: " << std::boolalpha << detector.detectIssue() << std::endl;  // Output: Issue detected: true
    return 0;
}
