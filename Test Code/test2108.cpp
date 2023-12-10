int custom_floor(double x) {
    if (x >= 0) {
        return static_cast<int>(x);
    } else {
        int intPart = static_cast<int>(x);
        return (x == intPart) ? intPart : intPart - 1;
    }
}
