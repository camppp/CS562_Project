public class Character {
    private int wis; // Constructor to initialize wisdom attribute

    public Character(int wis) {
        this.wis = wis;
    }

    // The total power is calculated as the square of the wisdom attribute
    // Method signature: public int calculatePower()
    public int calculatePower() {
        return wis * wis;
    }
}