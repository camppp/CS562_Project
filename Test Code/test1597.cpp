size_t calculateArraySize(const TypeSet& typeSet, const Type& elemType, size_t numElems, const ArrayLayout::ArrayTripleList& arrayTripleList) {
    size_t totalSize = 0;
    for (const auto& triple : arrayTripleList) {
        size_t startIndex = triple.first;
        size_t size = triple.second;
        size_t stride = triple.third;
        totalSize += (size * stride) * typeSet.getDataLayout().getTypeAllocSize(elemType);
    }
    return totalSize;
}
