#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class Joint {
public:
    virtual double getAngle() const = 0;
};

class RevoluteJoint : public Joint {
private:
    double angle;

public:
    RevoluteJoint(double a) : angle(a) {}

    double getAngle() const override {
        return angle;
    }
};

bool compareJointConfigurations(const std::vector<std::shared_ptr<Joint>>& result, const std::vector<std::shared_ptr<Joint>>& expected) {
    if (result.size() != expected.size()) {
        return false;
    }

    for (size_t i = 0; i < result.size(); ++i) {
        if (std::abs(result[i]->getAngle() - expected[i]->getAngle()) > 1e-6) {
            return false;
        }
    }

    return true;
}

int main() {
    // Populate the expected joint configurations
    std::vector<std::shared_ptr<Joint>> expected = {
        std::make_shared<RevoluteJoint>(0),
        std::make_shared<RevoluteJoint>(0),
        std::make_shared<RevoluteJoint>(0),
        std::make_shared<RevoluteJoint>(1.5708),
        std::make_shared<RevoluteJoint>(1.5708),
        std::make_shared<RevoluteJoint>(-1.5708)
    };

    // Call the IK solver and obtain the result
    // Assume result is populated with the computed joint configurations

    // Compare the result with the expected joint configurations
    if (compareJointConfigurations(result, expected)) {
        std::cout << "Result matches expected joint configurations" << std::endl;
    } else {
        std::cout << "Result does not match expected joint configurations" << std::endl;
    }

    return 0;
}
