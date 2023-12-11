void fourop(int x, int y, int (*add)(int, int), int (*min)(int, int), int (*mult)(int, int), int (*div)(int, int)) {
    int result_add = add(x, y);
    int result_min = min(x, y);
    int result_mult = mult(x, y);
    int result_div = div(x, y);

    cout << "x + y = " << result_add << endl;
    cout << "x - y = " << result_min << endl;
    cout << "x * y = " << result_mult << endl;
    cout << "x / y = " << result_div << endl;
}
