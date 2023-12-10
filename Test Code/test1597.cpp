size_t calculateArraySize(const TypeSet& typeSet, const Type& elemType, size_t numElems, const ArrayLayout::ArrayTripleList& arrayTripleList) {
    auto elemSize = typeSet.getDataLayout().getTypeAllocSize(elemType);
    size_t totalSize = numElems * elemSize;

    for (const auto& triple : arrayTripleList) {
        totalSize *= triple.size;
    }

    return totalSize;
}
