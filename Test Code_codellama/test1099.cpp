int closest(int c) {
    int op1 = *std::lower_bound(options.begin(), options.end(), c);
    int op2 = *std::prev(std::upper_bound(options.begin(), options.end(), c));

    if (std::abs(op1 - c) < std::abs(op2 - c))
        return op1;
    return op2;
}
