java
public class MaxAbsDifference {
    public static int maxAbsDifference(int[] arrC, int x, int y) {
        int countX = 0, countY = 0;
        for (int i = 0; i < arrC.length; i++) {
            if (arrC[i] == x) {
                countX++;
            } else if (arrC[i] == y) {
                countY++;
            }
        }
        return Math.abs(countX - countY);
    }

    public static void main(String[] args) {
        int[] arrC = {1, -1, 1, 1, -1, -1, 1, 1};
        int x = 1, y = -1;
        System.out.println(maxAbsDifference(arrC, x, y)); // Output: 6
    }
}
