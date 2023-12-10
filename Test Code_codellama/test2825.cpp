bool checkLayer(Layer* layer) {
    if (layer == nullptr) {
        return false;
    }

    return layer->isSpatial();
}
