java
public class ArrayProcessor {
    public int calculateResult(int[] arr) {
        int sumOfEven = 0;
        int productOfOdd = 1;
        boolean oddPresent = false;

        for (int num : arr) {
            if (num % 2 == 0) {
                sumOfEven += num;
            } else {
                productOfOdd *= num;
                oddPresent = true;
            }
        }

        if (sumOfEven > 100) {
            return sumOfEven;
        } else if (oddPresent) {
            return productOfOdd;
        } else {
            return 0;
        }
    }
}
