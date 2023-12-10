#include <iostream>

class CpuTime {
public:
    double user = 0.0;
    double kernel = 0.0;

    // Add user time
    void operator+=(double user_step) {
        user += user_step;
    }

    // Add kernel time
    void addKernelTime(double kernel_step) {
        kernel += kernel_step;
    }

    // Calculate total CPU time
    double getTotalCpuTime() {
        return user + kernel;
    }
};

int main() {
    CpuTime time;
    double user_step = 0.5;
    double kernel_step = 0.3;
    int count = 10;

    time += user_step * count;
    time.addKernelTime(kernel_step * count);

    std::cout << "Total CPU time: " << time.getTotalCpuTime() << " seconds" << std::endl;

    return 0;
}
