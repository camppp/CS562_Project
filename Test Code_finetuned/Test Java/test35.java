public class Engine {
    public void start() {
        // Start the engine
    }

    public void stop() {
        // Stop the engine
    }

    // Other methods to monitor engine performance
}

public class SportDriverControls {
    private Engine engine;
    private int speed;
    private int handling;

    public SportDriverControls(Engine engine) {
        this.engine = engine;
        this.speed = 0;
        this.handling = 5; // Default handling level
    }

    public void increaseSpeed(int amount) {
        // Implement this method to increase the speed of the car
        this.speed += amount;
    }

    public void decreaseSpeed(int amount) {
        // Implement this method to decrease the speed of the car
        this.speed -= amount;
    }

    public void adjustHandling(int level) {
        // Implement this method to adjust the handling of the car
        this.handling = level;
    }
}