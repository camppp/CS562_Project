#include <iostream>
#include <ctime>

class ttime {
public:
    time_t time_get();
    void wait(int index);
};

time_t ttime::time_get() {
    time_t tmp;
    time(&tmp);
    return tmp;
}

void ttime::wait(int index) {
    time_t start = time_get();
    while (time_get() - start < index) {
        // do nothing
    }
}

int main() {
    ttime my_time;
    std::cout << "Current time: " << my_time.time_get() << std::endl;
    my_time.wait(5);
    std::cout << "Waited for 5 seconds" << std::endl;
    std::cout << "Current time: " << my_time.time_get() << std::endl;
    return 0;
}
