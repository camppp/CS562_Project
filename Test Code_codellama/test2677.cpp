int maxTrianglePerimeter(int a[]) {
    int n = sizeof(a) / sizeof(a[0]);
    int maxPerimeter = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int perimeter = a[i] + a[j] + a[k];
                if (perimeter > maxPerimeter) {
                    maxPerimeter = perimeter;
                }
            }
        }
    }
    return maxPerimeter;
}
