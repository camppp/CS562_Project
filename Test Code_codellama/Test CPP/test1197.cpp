class EuclideanVector {
 public:
  // ...

  operator std::vector<double>() const {
    std::vector<double> result;
    result.reserve(dimensions_);
    for (int i = 0; i < dimensions_; i++) {
      result.push_back(magnitudes_[i]);
    }
    return result;
  }

 private:
  std::vector<double> magnitudes_;
  int dimensions_;
};
