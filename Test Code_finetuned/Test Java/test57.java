import java.util.HashSet;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        HashSet<Integer> set = new HashSet<>();
        randomSet(1, 10, 5, set);
        System.out.println(set);
    }

    public static void randomSet(int min, int max, int n, HashSet<Integer> set) {
        if (n > (max - min + 1) || max < min) {
            System.out.println("Impossible to generate " + n + " distinct integers within the range [" + min + ", " + max + "]");
            return;
        }

        Random rand = new Random();
        while (set.size() < n) {
            int randomNum = rand.nextInt((max - min) + 1) + min;
            set.add(randomNum);
        }
    }
}