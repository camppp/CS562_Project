const char* getVertexDataCacheName(bool imageOrDerived) {
    return imageOrDerived ? "mVertexDataCache" : "mVertexData";
}
