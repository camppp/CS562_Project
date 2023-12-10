#include <iterator>
#include <unordered_map>

template <typename ObjInputIt, typename IdOutputIt>
void processObjects(ObjInputIt first, ObjInputIt last, IdOutputIt result) {
    std::unordered_map<typename std::iterator_traits<ObjInputIt>::value_type, int> idMap;
    int idCounter = 0;

    for (auto it = first; it != last; ++it) {
        auto obj = *it;
        auto idIt = idMap.find(obj);
        if (idIt == idMap.end()) {
            *result = idCounter;  // Write the identifier to the output iterator
            idMap[obj] = idCounter++;
        } else {
            *result = idIt->second;  // Write the existing identifier to the output iterator
        }
        ++result;
    }
}
