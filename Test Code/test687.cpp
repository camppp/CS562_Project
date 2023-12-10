template <class PtrLike, class Comparator = less<>>
void PushHeap(PtrLike begin, PtrLike end, Comparator comparator = Comparator()) {
    size_type i = end - begin - 1;
    while (i > 0) {
        size_type parent = (i - 1) / 2;
        if (comparator(*(begin + parent), *(begin + i))) {
            std::swap(*(begin + parent), *(begin + i));
            i = parent;
        } else {
            break;
        }
    }
}
