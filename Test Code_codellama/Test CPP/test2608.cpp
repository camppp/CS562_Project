void processColors(Color* colors, int max_iter, int num_shades, const Color* mapping, int size) {
    for (int i = 0; i < size; i++) {
        Color& color = colors[i];
        if (color.red == max_iter || color.red == 0) {
            color.red = 0;
            color.green = 0;
            color.blue = 0;
        } else {
            int uc = color.red % num_shades;
            color = mapping[uc];
        }
    }
}
