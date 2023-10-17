import java.util.InputMismatchException;
import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter the first number: ");
            double firstNumber = scanner.nextDouble();

            System.out.print("Enter the second number: ");
            double secondNumber = scanner.nextDouble();

            double sum = firstNumber + secondNumber;
            System.out.println("Sum: " + sum);
        } catch (InputMismatchException e) {
            System.out.println("Input error: Please enter valid numeric values.");
        } finally {
            scanner.close();
        }
    }
}
