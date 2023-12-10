#include <unordered_set>

template <typename T>
class UniqueCollection {
public:
    void add(const T& element) {
        elements.insert(element);
    }

    void remove(const T& element) {
        elements.erase(element);
    }

    bool contains(const T& element) const {
        return elements.find(element) != elements.end();
    }

    size_t size() const {
        return elements.size();
    }

private:
    std::unordered_set<T> elements;
};
