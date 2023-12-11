public class ArraySumAndNextValue {
    public static void main(String[] args) {
        int[] data = {3, 7, 11, 15, 19};
        int sum = 0;
        for (int i = 0; i < data.length; i++) {
            System.out.println("Next value: " + data[i]);
            sum += i;
        }
        System.out.println("Sum is: " + sum);
    }
}