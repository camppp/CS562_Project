#include <unordered_map>

template <typename ElemT, typename HandleT>
class GenericDataStructure {
public:
    using ElementType = ElemT;
    using HandleType = HandleT;

private:
    std::unordered_map<HandleType, ElementType> data;

public:
    // Adds an element to the data structure and returns a handle to the added element
    HandleType add(const ElementType& element) {
        static HandleType nextHandle = 0;  // Assuming HandleType supports increment
        data[nextHandle] = element;
        return nextHandle++;
    }

    // Retrieves the element associated with the given handle
    ElementType get(const HandleType& handle) const {
        auto it = data.find(handle);
        if (it != data.end()) {
            return it->second;
        } else {
            // Handle not found, handle error accordingly
            throw std::out_of_range("Handle not found");
        }
    }

    // Removes the element associated with the given handle from the data structure
    void remove(const HandleType& handle) {
        data.erase(handle);
    }
};
