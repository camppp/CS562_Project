#include <array>
#include <cstdint>
#include <algorithm>

namespace native {
  struct guid {
    static guid new_guid() {
      // Implementation of generating a new GUID
      return guid();
    }
  };
}

class guid {
private:
  std::array<uint8_t, 16> data_;

public:
  bool equals(const guid& g) const noexcept {
    for (size_t index = 0; index < 16; index++)
      if (data_[index] != g.data_[index]) return false;
    return true;
  }

  static guid new_guid() noexcept {
    return guid(native::guid::new_guid());
  }

  // Constructor to initialize from native GUID
  guid(const native::guid& nativeGuid) {
    std::copy(nativeGuid.data_.begin(), nativeGuid.data_.end(), data_.begin());
  }
};
