CropLayer& CropLayer::setOffset(const std::vector<size_t>& offsets) {
    // Check if the offsets vector has the correct size
    if (offsets.size() != 4) {
        throw std::invalid_argument("Invalid offset vector size");
    }

    // Set the offsets for cropping the image
    top_ = offsets[0];
    bottom_ = offsets[1];
    left_ = offsets[2];
    right_ = offsets[3];

    return *this;
}
