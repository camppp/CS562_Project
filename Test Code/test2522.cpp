#include <iostream>
#include <vector>
#include <map>

using my_float = double;

class ARSeq {
private:
    std::map<int, my_float> lag_coeff;
    std::vector<my_float> prev_val;
    my_float bias;

public:
    ARSeq(std::map<int, my_float> mp, my_float bias) : lag_coeff{mp}, bias{bias} {
        for (auto i = 0; i < max_lag; i++) {
            prev_val.push_back(0);
        }
    }

    void update(my_float val) {
        prev_val.erase(prev_val.begin());
        prev_val.push_back(val);
    }

    my_float predict_next() {
        my_float prediction = bias;
        for (auto i = 0; i < prev_val.size(); i++) {
            prediction += prev_val[i] * lag_coeff[i + 1];
        }
        return prediction;
    }
};

int main() {
    std::map<int, my_float> coefficients = {{1, 0.5}, {2, -0.3}, {3, 0.2}};
    my_float bias = 1.0;
    ARSeq ar_seq(coefficients, bias);

    ar_seq.update(2.0);
    ar_seq.update(1.5);
    ar_seq.update(0.8);

    std::cout << "Predicted next value: " << ar_seq.predict_next() << std::endl;

    return 0;
}
