class TripleCollection {
private:
    std::string m_id;
    std::vector<std::tuple<int, int, int>> m_triples;

public:
    TripleCollection(std::string id) : m_id(id) {}

    const std::string& id() const { return m_id; }

    std::size_t size() const { return m_triples.size(); }

    void addTriple(int a, int b, int c) {
        m_triples.push_back(std::make_tuple(a, b, c));
    }

    void removeTriple(int a, int b, int c) {
        auto it = std::find(m_triples.begin(), m_triples.end(), std::make_tuple(a, b, c));
        if (it != m_triples.end()) {
            m_triples.erase(it);
        }
    }

    std::tuple<int, int, int> getTriple(int index) const {
        return m_triples[index];
    }
};
