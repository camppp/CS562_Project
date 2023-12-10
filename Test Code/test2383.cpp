#include <iostream>
#include <cstddef>

template<typename eT, typename uword>
class podarray {
private:
    eT* data;  // Pointer to the array of elements
    uword size;  // Current size of the array

public:
    // Constructor to initialize the podarray with new_N elements from the array X
    explicit podarray(const eT* X, const uword new_N) {
        size = new_N;
        data = new eT[size];
        for (uword i = 0; i < size; ++i) {
            data[i] = X[i];
        }
    }

    // Constructor to initialize the podarray from a proxy object P
    template<typename T1>
    explicit podarray(const Proxy<T1>& P) {
        size = P.get_size();
        data = new eT[size];
        for (uword i = 0; i < size; ++i) {
            data[i] = P[i];
        }
    }

    // Overloaded operator for accessing and modifying the element at index i
    eT& operator[] (const uword i) {
        return data[i];
    }

    // Overloaded operator for accessing the element at index i in a read-only manner
    eT operator[] (const uword i) const {
        return data[i];
    }

    // Overloaded function call operator for accessing and modifying the element at index i
    eT& operator() (const uword i) {
        return data[i];
    }

    // Overloaded function call operator for accessing the element at index i in a read-only manner
    eT operator() (const uword i) const {
        return data[i];
    }

    // Function to resize the podarray to contain new_n_elem elements
    void set_size(const uword new_n_elem) {
        eT* new_data = new eT[new_n_elem];
        uword min_size = (new_n_elem < size) ? new_n_elem : size;
        for (uword i = 0; i < min_size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        size = new_n_elem;
    }

    // Function to reset the podarray by deallocating memory and setting its size to zero
    void reset() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    // Destructor to deallocate memory when the podarray object goes out of scope
    ~podarray() {
        delete[] data;
    }
};

int main() {
    // Example usage of the podarray class
    int arr[] = {1, 2, 3, 4, 5};
    podarray<int, size_t> myArray(arr, 5);
    std::cout << myArray[2] << std::endl;  // Output: 3
    myArray.set_size(3);
    std::cout << myArray[4] << std::endl;  // Output: Garbage value
    myArray.reset();
    return 0;
}
