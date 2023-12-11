const char* getVertexDataCacheName(bool imageOrDerived) {
    if (imageOrDerived) {
        return "mVertexDataCache";
    } else {
        return "mVertexData";
    }
}
