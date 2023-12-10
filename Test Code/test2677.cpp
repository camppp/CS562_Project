java
public int maxTrianglePerimeter(int[] a) {
    int n = a.length;
    int maxPerimeter = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int side1 = a[i];
                int side2 = a[j];
                int side3 = a[k];

                if (isTriangle(side1, side2, side3)) {
                    maxPerimeter = Math.max(maxPerimeter, side1 + side2 + side3);
                }
            }
        }
    }

    return maxPerimeter;
}

private boolean isTriangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}
