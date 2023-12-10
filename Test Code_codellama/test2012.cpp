#include <string>
#include <unordered_map>

class URIQuery {
public:
    void Insert(const std::string& key, const std::string& value) {
        query_map[key] = value;
    }

    std::string Str() const {
        std::string query_string;
        for (const auto& [key, value] : query_map) {
            query_string += "?" + key + "=" + value + "&";
        }
        return query_string.substr(0, query_string.length() - 1);
    }

private:
    std::unordered_map<std::string, std::string> query_map;
};
