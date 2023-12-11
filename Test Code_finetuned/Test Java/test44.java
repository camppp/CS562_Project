// Interface for classes that calculate distance
public interface DistanceCalculable {
    double getDistance();
}

// Class representing a 3D vector
class Vector3D {
    private double x, y, z;

    public Vector3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Method to calculate the magnitude of the vector
    public double getNorm() {
        return Math.sqrt(x * x + y * y + z * z);
    }
}

// Class representing a point in a 3D space
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
}