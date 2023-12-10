unsigned int calculateSum(const vec_type& vec) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}
