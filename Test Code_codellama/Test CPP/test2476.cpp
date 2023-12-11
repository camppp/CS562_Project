template <typename T>
struct type {
    static constexpr const char* name() {
        if constexpr (std::is_same_v<T, int>) {
            return "int";
        } else if constexpr (std::is_same_v<T, double>) {
            return "double";
        } else if constexpr (std::is_same_v<T, std::string>) {
            return "std::string";
        } else {
            return "unknown";
        }
    }
};

template <typename T>
struct conv {
    static T convert(const T& value) {
        if constexpr (std::is_same_v<T, int>) {
            return static_cast<T>(value);
        } else if constexpr (std::is_same_v<T, double>) {
            return static_cast<T>(value);
        } else if constexpr (std::is_same_v<T, std::string>) {
            return static_cast<T>(value);
        } else {
            return T();
        }
    }
};
