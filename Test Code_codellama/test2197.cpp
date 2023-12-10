java
public class Point2D {
    private int x;
    private int y;

    public Point2D(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public double distanceTo(Point2D other) {
        return Math.sqrt(Math.pow(other.x - this.x, 2) + Math.pow(other.y - this.y, 2));
    }

    public Point2D midpointWith(Point2D other) {
        return new Point2D((this.x + other.x) / 2, (this.y + other.y) / 2);
    }

    public boolean equals(Point2D other) {
        return this.x == other.x && this.y == other.y;
    }
}
