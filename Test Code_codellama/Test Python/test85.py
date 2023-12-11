def calculate_gantry_area(gx, gy, gh, line_length):
    rect_area = 2 * gx * gh
    tri_area = 0.5 * line_length * gy
    return rect_area + tri_area