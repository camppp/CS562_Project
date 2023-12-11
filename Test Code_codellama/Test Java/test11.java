import java.util.Arrays;

public class OptionPricing {
  public static double[] calculateOptionPrices(double[] strikes, double S_t, double X, double r, double t, double sigma) {
    double[] res = new double[strikes.length];
    for (int i = 0; i < strikes.length; i++) {
      double d1 = (Math.log(S_t / X) + (r + (sigma * sigma) / 2) * t) / (sigma * Math.sqrt(t));
      double d2 = d1 - sigma * Math.sqrt(t);
      res[i] = S_t * Math.exp(-r * t) * N(d1) - X * Math.exp(-r * t) * N(d2);
    }
    return res;
  }

  public static double N(double x) {
    return 0.5 + 0.5 * Math.erf(x / Math.sqrt(2));
  }
}