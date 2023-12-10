int findSecondLargest(const std::list<int>& lst) {
    int secondLargest = -1;
    int largest = -1;
    for (auto ite = lst.begin(); ite != lst.end(); ++ite) {
        if (*ite > largest) {
            secondLargest = largest;
            largest = *ite;
        } else if (*ite > secondLargest) {
            secondLargest = *ite;
        }
    }
    return secondLargest;
}
