java
public class MaxPointsCalculator {
    public static int maxPoints(int[] outcome) {
        int n = outcome.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (outcome[i] == 1) {
                count++;
                if (i < n - 1 && outcome[i + 1] == 1) {
                    count++;
                    i++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] outcome = {1, 0, 1, 1, 0, 1, 0, 0, 1};
        System.out.println(maxPoints(outcome)); // Output: 7
    }
}
