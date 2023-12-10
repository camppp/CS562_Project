#include <iostream>
#include <vector>

namespace iota {
    class Iota {
    private:
        int start;
        int count;
    public:
        Iota(int start, int count) : start(start), count(count) {}

        int operator[](int index) const {
            return start + index;
        }

        int size() const {
            return count;
        }

        class iterator {
        private:
            int current;
        public:
            iterator(int start) : current(start) {}

            int operator*() const {
                return current;
            }

            iterator& operator++() {
                ++current;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return current != other.current;
            }
        };

        iterator begin() const {
            return iterator(start);
        }

        iterator end() const {
            return iterator(start + count);
        }
    };

    class Model {
    public:
        static int sum(const Iota& sequence) {
            int result = 0;
            for (int i = 0; i < sequence.size(); ++i) {
                result += sequence[i];
            }
            return result;
        }

        static int product(const Iota& sequence) {
            int result = 1;
            for (int i = 0; i < sequence.size(); ++i) {
                result *= sequence[i];
            }
            return result;
        }

        static double average(const Iota& sequence) {
            return static_cast<double>(sum(sequence)) / sequence.size();
        }
    };
}

int main() {
    using namespace iota;
    using namespace model;

    Iota sequence(1, 5);
    std::cout << "Sum: " << Model::sum(sequence) << std::endl;
    std::cout << "Product: " << Model::product(sequence) << std::endl;
    std::cout << "Average: " << Model::average(sequence) << std::endl;

    return 0;
}
