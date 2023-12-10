public int calculateResult(int[] arr) {
    int sum = 0;
    int product = 1;

    for (int i = 0; i < arr.length; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        } else {
            product *= arr[i];
        }
    }

    if (sum > 100) {
        return sum;
    } else {
        return product;
    }
}
