#include <random>
#include <vector>

namespace randest {

template <typename OutputT>
class data_provider {
public:
    data_provider(int seed) : gen_(seed) {}

    std::vector<OutputT> generate(int count) {
        std::vector<OutputT> result;
        result.reserve(count);
        for (int i = 0; i < count; ++i) {
            result.push_back(generate_random());
        }
        return result;
    }

    void set_seed(int seed) {
        gen_.seed(seed);
    }

private:
    std::mt19937 gen_;

    OutputT generate_random() {
        if constexpr (std::is_integral_v<OutputT>) {
            return gen_() % std::numeric_limits<OutputT>::max();
        } else if constexpr (std::is_floating_point_v<OutputT>) {
            return gen_() * std::numeric_limits<OutputT>::max();
        } else {
            return OutputT();
        }
    }
};

} // namespace randest
