int scan(const std::vector<Predicate>& predicates, const std::vector<Record>& records) {
    int count = 0;
    for (const auto& record : records) {
        bool match = true;
        for (const auto& predicate : predicates) {
            if (!predicate.evaluate(record)) {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    return count;
}
