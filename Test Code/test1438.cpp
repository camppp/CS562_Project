java
public class LineSearch {
    public void advance_and_retreat(double a0, double h0, double t, double a, double b) {
        // Your implementation of advance_and_retreat method goes here
        // Example implementation:
        if (a0 < 3.0) {
            a = a0 + h0 * t;
        } else {
            a = a0 - h0 * t;
        }
        if (b < 3.0) {
            b = b + h0 * t;
        } else {
            b = b - h0 * t;
        }
    }
}
