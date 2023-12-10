#include <iostream>
#include <vector>

int findHIndex(const std::vector<int>& citations) {
    // Sort the citations in descending order
    std::vector<int> sortedCitations = citations;
    std::sort(sortedCitations.begin(), sortedCitations.end(), std::greater<int>());

    // Find the largest h such that the researcher has at least h papers with h or more citations
    int h = 0;
    while (h < sortedCitations.size() && sortedCitations[h] >= h) {
        h++;
    }

    return h;
}

int main() {
    std::vector<int> citations = {3, 0, 6, 1, 5};
    std::cout << findHIndex(citations) << std::endl; // Output: 3

    citations = {0, 1, 3, 5, 6};
    std::cout << findHIndex(citations) << std::endl; // Output: 3

    return 0;
}
