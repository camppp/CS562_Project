// Definition of the BinOp struct
template <typename T>
struct BinOp {
  static T neutral;  // Neutral element for the binary operation

  // Binary operation process function
  static T process(T val1, T val2) {
    // Define the binary operation process logic here
    return val1 + val2;  // Example: Addition operation
  }
};

// Define the neutral element for the binary operation
template <typename T>
T BinOp<T>::neutral = 0;  // Example: Neutral element for addition is 0

// Implementation of the generic algorithm
template <typename InputIterator1, typename InputIterator2, typename T1, typename T2, typename Container>
void processAndTransformData(InputIterator1 beg1, InputIterator1 end1, InputIterator2 beg2, const Container& NlList, const Container& vInbound, const Container& i_vin, Container& o_vout) {
  for (; beg1 != end1; ++beg1, ++beg2) {
    auto val = BinOp<T1>::neutral;
    for (const auto& idxnl : NlList) {
      auto currentidx = *beg1 + idxnl;
      if (!vInbound.contains(currentidx)) {
        continue;
      }
      val = BinOp<T1>::process(val, i_vin[currentidx]);
    }
    o_vout[*beg2] = static_cast<T2>(val);
  }
}
