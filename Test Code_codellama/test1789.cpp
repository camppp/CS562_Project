class RightTriangle {
public:
    int triangleCount(int places, int points, int a, int b, int c) {
        // Check if the number of places is odd
        if (places % 2 == 1) {
            return 0;
        }

        // Initialize the count to 0
        int count = 0;

        // Loop through all possible combinations of points
        for (int i = 0; i < places; i++) {
            for (int j = i + 1; j < places; j++) {
                for (int k = j + 1; k < places; k++) {
                    // Check if the points form a right-angled triangle
                    if (a * (j - i) == b * (k - i) && b * (k - j) == c * (i - j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
