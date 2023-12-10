namespace tdc {

static_assert(sizeof(int) * 8 == 32, "Make sure the logic here remains correct");

template<class T, class X = void>
struct ConstIntegerBaseTrait {
    using BaseType = T;
};

template<>
struct ConstIntegerBaseTrait<int> {
    using BaseType = int;
};

template<>
struct ConstIntegerBaseTrait<long> {
    using BaseType = long;
};

template<>
struct ConstIntegerBaseTrait<long long> {
    using BaseType = long long;
};

// Add specializations for other integral types as needed

}  // namespace tdc
