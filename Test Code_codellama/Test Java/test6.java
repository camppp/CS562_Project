public class Car {
    private int speed;
    private String owner;

    public void speedUp(final int newSpeed) {
        if (newSpeed > 0) {
            speed = newSpeed;
        }
    }

    public void setOwner(final String newOwner) {
        owner = newOwner;
    }
}