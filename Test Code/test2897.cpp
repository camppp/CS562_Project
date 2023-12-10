#include <iostream>
#include <map>
#include <string>

class StringManager {
public:
    StringManager() {}

    void addString(const std::string& strMoniker, const tCIDLib::TCard4 c4Id) {
        strings_.insert(std::make_pair(c4Id, strMoniker));
    }

    std::string getString(const tCIDLib::TCard4 c4Id) const {
        auto it = strings_.find(c4Id);
        if (it != strings_.end()) {
            return it->second;
        } else {
            return "";
        }
    }

    void removeString(const tCIDLib::TCard4 c4Id) {
        strings_.erase(c4Id);
    }

    tCIDLib::TCard4 getId(const std::string& strMoniker) const {
        for (auto it = strings_.begin(); it != strings_.end(); ++it) {
            if (it->second == strMoniker) {
                return it->first;
            }
        }
        return 0;
    }

private:
    std::map<tCIDLib::TCard4, std::string> strings_;
};
