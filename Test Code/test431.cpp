java
import java.util.Arrays;

class FractionalMultiplier {
    private int maxDigits;

    public FractionalMultiplier(int numDigits) {
        this.maxDigits = numDigits;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public int[] multiply(int[] fraction1, int[] fraction2) {
        int numerator = fraction1[0] * fraction2[0];
        int denominator = fraction1[1] * fraction2[1];
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        return reduceFraction(numerator, denominator);
    }

    private int[] reduceFraction(int numerator, int denominator) {
        int[] result = new int[2];
        result[0] = numerator;
        result[1] = denominator;
        if (result[0] != 0) {
            int gcd = gcd(Math.abs(result[0]), result[1]);
            result[0] /= gcd;
            result[1] /= gcd;
        }
        return result;
    }
}
