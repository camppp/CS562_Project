double calculateExpression(double x) {
    double a = getA();
    double c = getC();
    double A = getA();
    double alpha = getAlpha();
    double gamma = getGamma();

    return a * x * x + c * x + A * sin(alpha * x) + gamma;
}
