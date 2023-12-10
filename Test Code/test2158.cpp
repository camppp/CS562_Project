CropLayer& CropLayer::setOffset(const std::vector<size_t>& offsets) {
    if (offsets.size() != 4) {
        throw std::invalid_argument("Offset vector must contain exactly 4 values: {top, bottom, left, right}");
    }

    topOffset = offsets[0];
    bottomOffset = offsets[1];
    leftOffset = offsets[2];
    rightOffset = offsets[3];

    return *this;
}
