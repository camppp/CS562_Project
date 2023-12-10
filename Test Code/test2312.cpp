unsigned int eval_seq(void) {
    const unsigned int SCORE_MAX = 100;  // Example value, can be any positive integer
    double result = calculateResult();  // Assuming calculateResult() returns the result of the evaluation
    double max_result = calculateMaxResult();  // Assuming calculateMaxResult() returns the maximum possible result

    return (unsigned int)(SCORE_MAX * (result / max_result));
}
