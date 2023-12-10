template <int number, int divisor>
class IsPrime {
public:
    enum {
        primeNumber = (number == 2 || number % divisor != 0) && divisor * divisor <= number && IsPrime<number, divisor + 1>::primeNumber
    };
};

template <int number>
class IsPrime<number, 1> {
public:
    enum {
        primeNumber = number > 1
    };
};

template <int number, int current>
class PrimeNumberPrinter {
public:
    PrimeNumberPrinter<number, current - 1> printer;

    enum {
        isPrime = IsPrime<current, 2>::primeNumber
    };

    void print() {
        printer.print();
        if (isPrime) {
            std::cout << current << " ";
        }
    }
};

template <int number>
class PrimeNumberPrinter<number, 1> {
public:
    enum {
        isPrime = IsPrime<1, 2>::primeNumber
    };

    void print() {
        if (isPrime) {
            std::cout << "2 ";
        }
    }
};

int main() {
    PrimeNumberPrinter<20, 20> printer;
    printer.print();
    return 0;
}
