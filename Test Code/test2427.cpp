java
public int calculateSum(int[][] b) {
    int sum = 0;
    for (int[] row : b) {
        for (int element : row) {
            sum += element;
        }
    }
    return sum;
}
