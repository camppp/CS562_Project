#include <vector>
#include <cstring> // for memcpy

template <typename TRet>
void yourFunction(void* val, size_t bytes, std::vector<TRet>& result) {
    // Missing part: Process input parameters and populate the result vector

    if (bytes > 0) {
        // Interpret val pointer as TRet* and push the value into the result vector
        TRet value;
        std::memcpy(&value, val, bytes);
        result.push_back(value);
    }
    // If bytes is zero, do nothing (optional else branch)
}
