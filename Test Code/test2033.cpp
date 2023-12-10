#include <cmath>

class ExpressionCalculator {
private:
    double a;
    double c;
    double A;
    double alpha;
    double gamma;

public:
    void initializeVariables(double a, double c, double A, double alpha, double gamma) {
        this->a = a;
        this->c = c;
        this->A = A;
        this->alpha = alpha;
        this->gamma = gamma;
    }

    double calculateExpression(double x) {
        return a * x * x + c * x + A * sin(alpha * x) + gamma;
    }
};

int main() {
    ExpressionCalculator calculator;
    calculator.initializeVariables(400.0, 1.0, 50.0, 0.602, 0.101);
    double result = calculator.calculateExpression(2.0);
    // Output the result or use it as needed
    return 0;
}
