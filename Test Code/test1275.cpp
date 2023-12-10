struct feed_index {
    int quote_id;
    int delegate_id;

    friend bool operator==(const feed_index& a, const feed_index& b) {
        return std::tie(a.quote_id, a.delegate_id) == std::tie(b.quote_id, b.delegate_id);
    }
};
