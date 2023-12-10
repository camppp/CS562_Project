#include <memory>
#include <vector>
#include <cstdint>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace detail {

template <typename T>
class PtrMaybe {
private:
    std::unique_ptr<T> value;

public:
    PtrMaybe() : value(nullptr) {}

    bool isJust() const {
        return value != nullptr;
    }

    T* fromMaybe(T* defaultValue) const {
        return value ? value.get() : defaultValue;
    }

    T* fromJust() const {
        if (!value) {
            throw std::logic_error("Maybe is Nothing");
        }
        return value.get();
    }

    std::unique_ptr<T> takeJust() {
        if (!value) {
            throw std::logic_error("Maybe is Nothing");
        }
        return std::move(value);
    }

    PtrMaybe& operator=(std::unique_ptr<T> newValue) {
        value = std::move(newValue);
        return *this;
    }
};

}  // namespace detail

TEST(PtrMaybeTest, SmokeTest) {
  detail::PtrMaybe<std::vector<uint32_t>> example;
  EXPECT_FALSE(example.isJust());
  EXPECT_TRUE(nullptr == example.fromMaybe(nullptr));
  std::unique_ptr<std::vector<uint32_t>> v(new std::vector<uint32_t>);
  v->push_back(42);
  v->push_back(21);
  example = std::move(v);
  EXPECT_TRUE(example.isJust());
  EXPECT_THAT(*example.fromJust(), testing::ElementsAre(42, 21));
  std::unique_ptr<std::vector<uint32_t>> out = example.takeJust();
  EXPECT_FALSE(example.isJust());
}
