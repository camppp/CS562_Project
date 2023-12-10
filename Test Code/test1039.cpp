/**
 * @brief Student's t probability density function: In-database interface
 */
AnyType students_t_pdf::run(AnyType &args) {
    double t = args[0].getAs<double>();  // Value at which to evaluate the PDF
    double df = args[1].getAs<double>(); // Degrees of freedom

    // Calculate the PDF using the formula
    double numerator = tgamma((df + 1) / 2);
    double denominator = sqrt(df * M_PI) * tgamma(df / 2);
    double pdf = numerator / denominator * pow(1 + pow(t, 2) / df, -(df + 1) / 2);

    return pdf; // Return the calculated PDF
}
