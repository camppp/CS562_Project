template <typename ObjInputIt, typename IdOutputIt>
void processObjects(ObjInputIt first, ObjInputIt last, IdOutputIt result) {
    int id = 0;
    for (auto it = first; it != last; ++it) {
        *result++ = id++;
    }
}
