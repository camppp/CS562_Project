#define VALIDATE_NOT_NULL(result) \
    if (result == nullptr) { \
        throw std::runtime_error("Null pointer exception"); \
    }

void processData(int* data) {
    VALIDATE_NOT_NULL(data);
    // Do something with data
}
