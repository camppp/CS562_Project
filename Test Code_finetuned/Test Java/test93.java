public class WaterMeter {
    private int id;
    private String location;
    private double reading;

    public WaterMeter(int id, String location, double reading) {
        this.id = id;
        this.location = location;
        this.reading = reading;
    }

    public void updateReading(double newReading) {
        this.reading = newReading;
    }

    public double calculateUsage(double previousReading) {
        return this.reading - previousReading;
    }

    // Getters and setters for id, location and reading
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public double getReading() {
        return reading;
    }

    public void setReading(double reading) {
        this.reading = reading;
    }
}