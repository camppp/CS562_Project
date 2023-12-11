#include <iostream>
#include <cmath>

float GammaP(float a, float x) {
    float gamma = 0.0f;
    float p = 1.0f;
    float q = 1.0f;
    float term = 1.0f;
    int i = 1;

    while (term > 0.00001f) {
        p *= (a + i - 1) / i;
        q *= x / (a + i);
        term = p / q;
        gamma += term;
        i++;
    }

    return gamma;
}

int main() {
    float a = 2.0f;
    float x = 3.0f;
    float result = GammaP(a, x);
    std::cout << "P(" << a << ", " << x << ") = " << result << std::endl;
    return 0;
}
