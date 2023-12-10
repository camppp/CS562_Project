#include <cstddef>

template <typename T>
size_t calculateStructureSize() {
    struct HelperStruct {
        T t;
        char c;
    };

    return offsetof(HelperStruct, c);
}
