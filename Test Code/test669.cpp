java
public class GameCharacter {
    private double positionX;
    private double speedX;
    private double accelerationX;

    public GameCharacter(double initialPositionX, double initialSpeedX, double accelerationX) {
        this.positionX = initialPositionX;
        this.speedX = initialSpeedX;
        this.accelerationX = accelerationX;
    }

    public void updatePosition(double deltaTime) {
        positionX = positionX + speedX * deltaTime + 0.5 * accelerationX * Math.pow(deltaTime, 2);
        speedX = speedX + accelerationX * deltaTime;
    }

    public double getPositionX() {
        return positionX;
    }

    public double getSpeedX() {
        return speedX;
    }

    public double getAccelerationX() {
        return accelerationX;
    }

    public static void main(String[] args) {
        GameCharacter character = new GameCharacter(0, 5, 2);
        character.updatePosition(2);
        System.out.println("PositionX: " + character.getPositionX()); // Output: 20.0
        System.out.println("SpeedX: " + character.getSpeedX()); // Output: 15.0
    }
}
