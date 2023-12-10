java
public class SumOfThousandsAndHundreds {
    public static int sumOfThousandsAndHundreds(int n) {
        if (n < 100) {
            return -1; // Return -1 if n has less than three digits
        } else {
            int thousand = n / 1000; // Calculate the digit in the thousands place
            int hundred = (n - (thousand * 1000)) / 100; // Calculate the digit in the hundreds place
            return thousand + hundred; // Return the sum of the digits in the thousands and hundreds place
        }
    }

    public static void main(String[] args) {
        int n1 = 12345;
        int n2 = 789;
        System.out.println("Sum of thousands and hundreds for " + n1 + ": " + sumOfThousandsAndHundreds(n1)); // Output: 3
        System.out.println("Sum of thousands and hundreds for " + n2 + ": " + sumOfThousandsAndHundreds(n2)); // Output: 15
    }
}
