#include <cstddef>
#include <limits>
#include <type_traits>

template <typename... Ts>
struct SequenceUtility {
    template <typename T>
    struct Index {
        static constexpr size_t value = [&] {
            size_t index = 0;
            for (auto& t : Ts) {
                if (std::is_same_v<T, t>) {
                    return index;
                }
                index++;
            }
            return std::numeric_limits<size_t>::max();
        }();
    };

    template <typename T>
    struct Contains {
        static constexpr bool value = [&] {
            for (auto& t : Ts) {
                if (std::is_same_v<T, t>) {
                    return true;
                }
            }
            return false;
        }();
    };
};
