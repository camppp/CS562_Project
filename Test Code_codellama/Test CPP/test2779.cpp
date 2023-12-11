#include <cstdint>

namespace mikodev::binary::converters {

class basic_empty_counter {
public:
    void increment() {
        ++count_;
    }

    int get_count() const {
        return count_;
    }

private:
    int count_ = 0;
};

class basic_push_back_adder {
public:
    void add(int value) {
        sum_ += value;
    }

    int get_sum() const {
        return sum_;
    }

private:
    int sum_ = 0;
};

} // namespace mikodev::binary::converters
