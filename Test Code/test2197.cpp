java
public class Point2D {
    private double x;
    private double y;

    public Point2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distanceTo(Point2D other) {
        double dx = this.x - other.x;
        double dy = this.y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public Point2D midpointWith(Point2D other) {
        double midX = (this.x + other.x) / 2.0;
        double midY = (this.y + other.y) / 2.0;
        return new Point2D(midX, midY);
    }

    public boolean equals(Point2D other) {
        return this.x == other.x && this.y == other.y;
    }

    // Additional methods, getters, setters, etc. can be added as needed
}
