#include <iostream>

template <typename eT>
class podarray {
public:
    explicit podarray(const eT* X, const uword new_N) {
        // Allocate memory for the array
        data = new eT[new_N];
        // Copy the elements from the input array
        for (uword i = 0; i < new_N; i++) {
            data[i] = X[i];
        }
        // Set the size of the array
        n_elem = new_N;
    }

    explicit podarray(const Proxy<T1>& P) {
        // Allocate memory for the array
        data = new eT[P.n_elem];
        // Copy the elements from the proxy object
        for (uword i = 0; i < P.n_elem; i++) {
            data[i] = P(i);
        }
        // Set the size of the array
        n_elem = P.n_elem;
    }

    eT& operator[] (const uword i) {
        // Check if the index is out of bounds
        if (i >= n_elem) {
            throw std::out_of_range("Index out of bounds");
        }
        // Return the element at the specified index
        return data[i];
    }

    eT operator[] (const uword i) const {
        // Check if the index is out of bounds
        if (i >= n_elem) {
            throw std::out_of_range("Index out of bounds");
        }
        // Return the element at the specified index
        return data[i];
    }

    eT& operator() (const uword i) {
        // Check if the index is out of bounds
        if (i >= n_elem) {
            throw std::out_of_range("Index out of bounds");
        }
        // Return the element at the specified index
        return data[i];
    }

    eT operator() (const uword i) const {
        // Check if the index is out of bounds
        if (i >= n_elem) {
            throw std::out_of_range("Index out of bounds");
        }
        // Return the element at the specified index
        return data[i];
    }

    void set_size(const uword new_n_elem) {
        // Check if the new size is valid
        if (new_n_elem <= 0) {
            throw std::invalid_argument("Invalid size");
        }
        // Deallocate the current memory
        delete[] data;
        // Allocate new memory for the array
        data = new eT[new_n_elem];
        // Set the size of the array
        n_elem = new_n_elem;
    }

    void reset() {
        // Deallocate the current memory
        delete[] data;
        // Set the size of the array to zero
        n_elem = 0;
    }

private:
    eT* data;
    uword n_elem;
};
