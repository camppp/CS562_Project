#include <iostream>
#include <cmath>

void performOperations(int dsigma[], int k, int iwk1, int iwk2, int iwk3) {
    for (int i = 0; i < k; i++) {
        dsigma[i] = Rlamc3(dsigma[i], dsigma[i]) - dsigma[i];
    }
    iwk1 = 1;
    iwk2 = iwk1 + k;
    iwk3 = iwk2 + k;
}

int main() {
    int dsigma[] = {1, 2, 3, 4, 5};
    int k = 3;
    int iwk1, iwk2, iwk3;
    performOperations(dsigma, k, iwk1, iwk2, iwk3);
    for (int i = 0; i < k; i++) {
        std::cout << dsigma[i] << " ";
    }
    std::cout << std::endl;
    std::cout << iwk1 << " " << iwk2 << " " << iwk3 << std::endl;
    return 0;
}
