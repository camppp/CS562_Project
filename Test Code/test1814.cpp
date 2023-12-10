template<typename T, int N>
class HybridMassDensityPolicy {
public:
    // Constructor
    HybridMassDensityPolicy(T weight_scale) : weight_scale_(weight_scale) {}

    // Member functions
    T weightScale(int dimension) {
        if (dimension == 0) {
            return weight_scale_;
        } else {
            return 1.0;
        }
    }

private:
    T weight_scale_;
};
