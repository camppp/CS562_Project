public class LineSearch {
    public void advance_and_retreat(double a0, double h0, double t, double a, double b) {
        a = a0 + t * h0;
        b = a0 - t * h0;
        ASSERT_LE(a, 3.0);
        ASSERT_GE(b, 3.0);
    }
}
