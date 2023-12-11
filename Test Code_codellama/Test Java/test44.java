public class Point3D implements DistanceCalculable {
    private Vector3D position;

    // Constructor to initialize the position
    public Point3D(Vector3D position) {
        this.position = position;
    }

    // Override method to calculate the distance from the origin
    @Override
    public double getDistance() {
        return position.getNorm();
    }

    // Your task is to complete the class by implementing the missing parts
}

public class Vector3D {
    private double x, y, z;

    // Constructor to initialize the vector
    public Vector3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Method to calculate the magnitude of the vector
    public double getNorm() {
        return Math.sqrt(x * x + y * y + z * z);
   