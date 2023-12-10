void resizeImage(Image* img, int newWidth, int newHeight) {
    int* newData = (int*)malloc(newWidth * newHeight * sizeof(int));
    double x_ratio = img->width / (double)newWidth;
    double y_ratio = img->height / (double)newHeight;
    double px, py;
    int newIdx = 0;

    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            px = j * x_ratio;
            py = i * y_ratio;
            int x = (int)px;
            int y = (int)py;
            int index = y * img->width + x;

            int a = img->data[index];
            int b = img->data[index + 1];
            int c = img->data[index + img->width];
            int d = img->data[index + img->width + 1];

            double x_diff = px - x;
            double y_diff = py - y;

            int interpolated_value = (int)(a * (1 - x_diff) * (1 - y_diff) + b * (x_diff) * (1 - y_diff) + c * (y_diff) * (1 - x_diff) + d * (x_diff * y_diff));
            newData[newIdx++] = interpolated_value;
        }
    }

    free(img->data);
    img->data = newData;
    img->width = newWidth;
    img->height = newHeight;
}
