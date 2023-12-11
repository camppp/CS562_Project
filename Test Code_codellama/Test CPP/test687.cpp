template <class PtrLike, class Comparator = less<>>
void PushHeap(PtrLike begin, PtrLike end, Comparator comparator = Comparator()) {
    size_type i = end - begin - 1;
    while (i > 0 && comparator(*(begin + (i - 1) / 2), *(begin + i))) {
        std::swap(*(begin + i), *(begin + (i - 1) / 2));
        i = (i - 1) / 2;
    }
}
