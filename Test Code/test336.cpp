#include <cstddef>
#include <cstring>

class CustomStringView {
public:
    // Constructors
    constexpr CustomStringView() noexcept : data_(nullptr), size_(0) {}
    constexpr CustomStringView(const char* str) noexcept : data_(str), size_(std::strlen(str)) {}
    constexpr CustomStringView(const char* str, size_t len) noexcept : data_(str), size_(len) {}

    // Accessors
    constexpr const char* data() const noexcept { return data_; }
    constexpr size_t size() const noexcept { return size_; }

    // Element access
    constexpr char operator[](size_t pos) const { return data_[pos]; }

    // Comparison
    constexpr bool operator==(CustomStringView other) const noexcept {
        return size_ == other.size_ && std::strncmp(data_, other.data_, size_) == 0;
    }

    // Subview
    constexpr CustomStringView substr(size_t pos, size_t count = npos) const {
        if (pos > size_) pos = size_;
        if (count > size_ - pos) count = size_ - pos;
        return CustomStringView(data_ + pos, count);
    }

    // Find
    constexpr size_t find(char c, size_t pos = 0) const noexcept {
        if (pos >= size_) return npos;
        const char* result = std::strchr(data_ + pos, c);
        return result ? static_cast<size_t>(result - data_) : npos;
    }

    static constexpr size_t npos = -1;

private:
    const char* data_;
    size_t size_;
};
