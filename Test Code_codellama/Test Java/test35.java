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
        this.speed += amount;
        engine.start();
    }

    public void decreaseSpeed(int amount) {
        this.speed -= amount;
        engine.stop();
    }

    public void adjustHandling(int level) {
        this.handling = level;
        engine.setHandling(level);
    }
}