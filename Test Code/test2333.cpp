#include <list>

template <typename T>
void simulateObjListEnd(std::list<T>& objList) {
    objList.push_back(T(-1));  // Appending -1 to mark the end of the object list
}
