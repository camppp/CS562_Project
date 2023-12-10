#include <string>

namespace jni {
    struct fixed_string {
        const char* str;
    };
}

struct type;

template <typename Type, typename = void>
struct conv;

#define SIMPLE_TYPE(TYPE, JNI_TYPE, CODE)                    \
    template <>                                              \
    struct type<TYPE> {                                      \
        static constexpr auto name() noexcept {              \
            return jni::fixed_string{CODE};                  \
        }                                                    \
    };                                                       \
                                                             \
    template <>                                              \
    struct conv<TYPE> {                                      \
        static JNI_TYPE unpack(TYPE const& wrapped) {

// Specialization for int
SIMPLE_TYPE(int, int, "int")

// Specialization for double
SIMPLE_TYPE(double, double, "double")

// Specialization for std::string
template <>
struct type<std::string> {
    static constexpr auto name() noexcept {
        return jni::fixed_string{"std::string"};
    }
};

template <>
struct conv<std::string> {
    static const char* unpack(std::string const& wrapped) {
        return wrapped.c_str();
    }
};
