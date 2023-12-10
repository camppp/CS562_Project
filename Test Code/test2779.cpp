#include <iostream>

namespace mikodev::binary::converters
{
    class basic_empty_counter
    {
    private:
        int count;

    public:
        basic_empty_counter() : count(0) {}

        void increment()
        {
            count++;
        }

        int get_count() const
        {
            return count;
        }
    };

    class basic_push_back_adder
    {
    private:
        int sum;

    public:
        basic_push_back_adder() : sum(0) {}

        void add(int value)
        {
            sum += value;
        }

        int get_sum() const
        {
            return sum;
        }
    };
}

int main()
{
    mikodev::binary::converters::basic_empty_counter counter;
    counter.increment();
    counter.increment();
    std::cout << "Count: " << counter.get_count() << std::endl;

    mikodev::binary::converters::basic_push_back_adder adder;
    adder.add(5);
    adder.add(10);
    std::cout << "Sum: " << adder.get_sum() << std::endl;

    return 0;
}
