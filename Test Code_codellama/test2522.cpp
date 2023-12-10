#include <iostream>
#include <map>
#include <cmath>

class ARSeq {
public:
    ARSeq(const std::map<int, float>& lag_coefficients, float bias) :
        lag_coefficients_(lag_coefficients), bias_(bias) {}

    void update(float val) {
        // Remove the oldest value from the sequence
        sequence_.pop_front();

        // Add the new value to the sequence
        sequence_.push_back(val);
    }

    float predict_next() {
        float prediction = bias_;
        for (const auto& [lag, coeff]: lag_coefficients_) {
            prediction += coeff * sequence_[sequence_.size() - lag - 1];
        }
        return prediction;
    }

private:
    std::map<int, float> lag_coefficients_;
    float bias_;
    std::deque<float> sequence_;
};
