java
public class LiquidContainer {
    private double startVol;
    private double endVol;
    private boolean firstVol;

    public LiquidContainer() {
        startVol = 0.0;
        endVol = 0.0;
        firstVol = true;
    }

    public String fill(double volume) {
        if (firstVol) {
            startVol = volume;
            firstVol = false;
            return "Container filled with " + volume + " units of liquid";
        } else {
            return "Container already filled";
        }
    }

    public void empty() {
        endVol = startVol;
        startVol = 0.0;
    }

    public double getCurrentVolume() {
        return startVol;
    }
}
