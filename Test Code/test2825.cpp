bool checkLayer(Layer* layer) {
    if (layer == nullptr) {
        return false;  // If layer is null, return false
    }
    return layer->isSpatial();  // If layer is not null, return the result of isSpatial()
}
