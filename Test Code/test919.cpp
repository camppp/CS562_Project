#include <iostream>
#include <vector>

namespace detail {

template <typename T>
class CustomIterator {
public:
    CustomIterator(const std::vector<T>& data, size_t index) : m_data(data), m_index(index) {}

    CustomIterator& operator++() {
        ++m_index;
        return *this;
    }

    CustomIterator operator++(int) {
        CustomIterator temp = *this;
        ++(*this);
        return temp;
    }

    T operator*() const {
        return m_data[m_index];
    }

    bool operator==(const CustomIterator& other) const {
        return m_index == other.m_index;
    }

    bool operator!=(const CustomIterator& other) const {
        return !(*this == other);
    }

private:
    const std::vector<T>& m_data;
    size_t m_index;
};

} // namespace detail

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    detail::CustomIterator<int> m_it(vec, 0);
    auto current = m_it++;
    std::cout << *current << std::endl; // Outputs: 1
    return 0;
}
