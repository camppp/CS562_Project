#include <string>
#include <vector>
#include <tuple>

class TripleCollection {
private:
    std::string m_id;
    std::vector<std::tuple<int, int, int>> m_triples;

public:
    const std::string &id() const { return m_id; }

    std::size_t size() const {
        return m_triples.size();
    }

    // Add any additional methods or constructors as needed
};
