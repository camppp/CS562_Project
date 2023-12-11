// FlyBehavior interface
public interface FlyBehavior {
    void fly();
}

// FlyNoWay class that implements FlyBehavior
public class FlyNoWay implements FlyBehavior {
    public void fly() {
        System.out.println("I am flying no way!");
    }
}

// FlyWithWings class that implements FlyBehavior
public class FlyWithWings implements FlyBehavior {
    public void fly() {
        System.out.println("I am flying with wings!");
    }
}