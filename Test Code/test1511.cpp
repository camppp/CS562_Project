template<int N>
class IsPrime {
public:
    static constexpr int primeNumber = (N % 2 == 0 && N > 2) ? 0 : 1;
};

template<int N>
class PrimeNumberPrinter {
public:
    static void printPrimeNumbers() {
        if (IsPrime<N>::primeNumber) {
            std::cout << N << " ";
        }
        if (N > 2) {
            PrimeNumberPrinter<N - 1>::printPrimeNumbers();
        }
    }
};
