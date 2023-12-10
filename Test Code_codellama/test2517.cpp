template <typename T>
std::vector<T> getitem_next_jagged_generic(const std::vector<T>& slicestarts,
                                           const std::vector<T>& slicestops,
                                           const std::vector<T>& slicecontent,
                                           const std::vector<T>& tail) {
  if (slicecontent.empty()) {
    return slicestarts;
  }

  std::vector<T> result;
  for (int i = 0; i < slicestarts.size(); i++) {
    T start = slicestarts[i];
    T stop = slicestops[i];
    T content = slicecontent[i];
    if (start < stop) {
      result.push_back(content);
    } else {
      result.push_back(tail[i]);
    }
  }
  return result;
}
