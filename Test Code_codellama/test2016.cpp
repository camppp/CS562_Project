#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/iterator.hpp>

using namespace boost::fusion;

// Define a fusion sequence
typedef vector<int, double, char> fusion_sequence;

// Define a custom iterator for the fusion sequence
typedef fusion::iterator<fusion_sequence, random_access_traversal_tag> fusion_iterator;

// Implement the custom iterator
fusion_iterator begin(fusion_sequence& seq) {
    return fusion_iterator(seq, 0);
}

fusion_iterator end(fusion_sequence& seq) {
    return fusion_iterator(seq, seq.size());
}

fusion_iterator& operator++(fusion_iterator& it) {
    it.advance(1);
    return it;
}

fusion_iterator& operator--(fusion_iterator& it) {
    it.advance(-1);
    return it;
}

fusion_iterator& operator+(fusion_iterator& it, int n) {
    it.advance(n);
    return it;
}

fusion_iterator& operator-(fusion_iterator& it, int n) {
    it.advance(-n);
    return it;
}

int operator-(fusion_iterator& it1, fusion_iterator& it2) {
    return it1.distance(it2);
}

// Use the custom iterator
int main() {
    fusion_sequence seq = {1, 2.0, 'a'};
    fusion_iterator it = begin(seq);
    std::cout << *it << std::endl;  // prints 1
    ++it;
    std::cout << *it << std::endl;  // prints 2.0
    --it;
    std::cout << *it << std::endl;  // prints 1
    it += 2;
    std::cout << *it << std::endl;  // prints 2.0
    it -= 2;
    std::cout << *it << std::endl;  // prints 1
    std::cout << it - begin(seq) << std::endl;  // prints 0
    std::cout << end(seq) - it << std::endl;  // prints 2
    return 0;
}
