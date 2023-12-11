bool operator==(const feed_index& lhs, const feed_index& rhs) {
    return lhs.quote_id == rhs.quote_id && lhs.delegate_id == rhs.delegate_id;
}
