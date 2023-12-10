#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

namespace randest {
    template<typename OutputT>
    class data_provider {
    private:
        std::mt19937 rng;  // Mersenne Twister random number engine
    public:
        data_provider(int seed) : rng(seed) {}

        std::vector<OutputT> generate(int count) {
            std::vector<OutputT> result;
            std::uniform_real_distribution<double> dist(0.0, 1.0);  // Default distribution for non-integer types

            for (int i = 0; i < count; ++i) {
                result.push_back(static_cast<OutputT>(dist(rng)));
            }

            return result;
        }

        void set_seed(int seed) {
            rng.seed(seed);
        }
    };
}
