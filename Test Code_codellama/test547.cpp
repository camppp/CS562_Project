#include <array>
#include <cstdint>

class guid {
public:
    guid() noexcept;
    guid(const guid& other) noexcept;
    guid(guid&& other) noexcept;
    ~guid() noexcept;

    guid& operator=(const guid& other) noexcept;
    guid& operator=(guid&& other) noexcept;

    bool equals(const guid& other) const noexcept;
    guid new_guid() noexcept;

private:
    std::array<uint8_t, 16> data_;
};

guid::guid() noexcept
    : data_{}
{
}

guid::guid(const guid& other) noexcept
    : data_{other.data_}
{
}

guid::guid(guid&& other) noexcept
    : data_{std::move(other.data_)}
{
}

guid::~guid() noexcept
{
}

guid& guid::operator=(const guid& other) noexcept
{
    data_ = other.data_;
    return *this;
}

guid& guid::operator=(guid&& other) noexcept
{
    data_ = std::move(other.data_);
    return *this;
}

bool guid::equals(const guid& other) const noexcept
{
    return data_ == other.data_;
}

guid guid::new_guid() noexcept
{
    return guid{native::guid::new_guid()};
}
