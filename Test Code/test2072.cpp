template<typename Range1, typename Range2>
bool equal(Range1 const& _range1, Range2 const& _range2) {
    auto it1 = std::begin(_range1);
    auto it2 = std::begin(_range2);
    const auto end1 = std::end(_range1);
    const auto end2 = std::end(_range2);

    while (it1 != end1 && it2 != end2) {
        if (*it1 != *it2) {
            return false;
        }
        ++it1;
        ++it2;
    }

    return (it1 == end1) && (it2 == end2);
}
