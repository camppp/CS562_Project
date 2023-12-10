int maxTrappedRainwater(int n, int buff[]) {
    int leftMax = 0, rightMax = 0;
    int left = 0, right = n - 1;
    int result = 0;

    while (left < right) {
        if (buff[left] < buff[right]) {
            if (buff[left] >= leftMax) {
                leftMax = buff[left];
            } else {
                result += leftMax - buff[left];
            }
            left++;
        } else {
            if (buff[right] >= rightMax) {
                rightMax = buff[right];
            } else {
                result += rightMax - buff[right];
            }
            right--;
        }
    }
    return result;
}
