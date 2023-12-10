#define CUSTOM_PRE_CONDITION(condition) \
    if (!(condition)) { \
        throw std::runtime_error("Pre-condition failed: " #condition); \
    }
