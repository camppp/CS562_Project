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

    T operator*() const {
        return m_data[m_index];
    }

    CustomIterator operator++(int) {
        CustomIterator temp = *this;
        ++m_index;
        return temp;
    }

    bool operator==(const CustomIterator& other) const {
        return m_index == other.m_index;
    }

    bool operator!=(const CustomIterator& other) const {
        return m_index != other.m_index;
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
    std::cout << *current << std::endl; // Should output: 1
    return 0;
}
