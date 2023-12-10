{
 public:
  template<class T>
  RTN(T new_value, AtomicType new_type)
      : value(new_value), type(new_type) {}

 private:
  T value;
  AtomicType type;
};
