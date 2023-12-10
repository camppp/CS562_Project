double random_double(int a, int c, int m, int& generator_state) {
    generator_state = (a * generator_state + c) % m;
    return static_cast<double>(generator_state) / m;
}
