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
