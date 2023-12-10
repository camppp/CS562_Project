#include <iostream>
#include <unordered_map>
#include <sstream>

class URIQuery {
private:
    std::unordered_map<std::string, std::string> queryMap;

public:
    void Insert(const std::string& key, const std::string& value) {
        queryMap[key] = value;
    }

    std::string Str() const {
        if (queryMap.empty()) {
            return "";
        }

        std::stringstream ss;
        ss << "?";
        for (auto it = queryMap.begin(); it != queryMap.end(); ++it) {
            ss << it->first << "=" << it->second;
            if (std::next(it) != queryMap.end()) {
                ss << "&";
            }
        }
        return ss.str();
    }
};

int main() {
    URIQuery query1, query2, query3;
    std::cout << "query1: " << query1.Str() << std::endl;  // Output: ""
    
    query1.Insert("key1", "value1");
    std::cout << "query1: " << query1.Str() << std::endl;  // Output: "?key1=value1"
    
    query1.Insert("key2", "value2");
    std::cout << "query1: " << query1.Str() << std::endl;  // Output: "?key1=value1&key2=value2"

    return 0;
}
