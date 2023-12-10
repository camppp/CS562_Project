template <typename T>
void simulateObjListEnd(std::list<T>& objList) {
    // Get the last element of the list
    auto lastElement = objList.back();

    // Check if the last element is already marked as the end of the list
    if (lastElement == -1) {
        // If the last element is already marked, do nothing
        return;
    }

    // Mark the last element as the end of the list
    objList.back() = -1;
}
