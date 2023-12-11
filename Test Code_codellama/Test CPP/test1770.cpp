std::pair<std::vector<unsigned>, std::vector<unsigned>> filterElements(const std::vector<unsigned>& A, unsigned average) {
    std::vector<unsigned> B;
    std::vector<unsigned> C;

    for (const auto& element : A) {
        if (element > average) {
            B.push_back(element);
        } else {
            C.push_back(element);
        }
    }

    return {B, C};
}
