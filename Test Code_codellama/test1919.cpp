#include <mutex>
#include <string>
#include <unordered_set>

class IdentifierManager {
public:
    IdentifierManager(std::mutex* mtx) : pStrMtx(mtx) {}

    void addIdentifier(const std::string& id) {
        std::lock_guard<std::mutex> lock(*pStrMtx);
        identifiers.insert(id);
    }

    void removeIdentifier(const std::string& id) {
        std::lock_guard<std::mutex> lock(*pStrMtx);
        identifiers.erase(id);
    }

    bool isIdentifierExists(const std::string& id) {
        std::lock_guard<std::mutex> lock(*pStrMtx);
        return identifiers.find(id) != identifiers.end();
    }

private:
    std::mutex* pStrMtx;
    std::unordered_set<std::string, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::string>>> identifiers;
};
