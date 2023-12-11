void add_value(Matrix* c, int rows, int cols, double p) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c->set_val(i, j, c->get_val(i, j) + p);
        }
    }
}
