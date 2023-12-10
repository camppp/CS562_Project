java
class Object {
    public Object() {
        System.out.println("Object constructor called");
    }
}

class Component extends Object {
    public Component() {
        System.out.println("Component constructor called");
    }
}

class Behaviour extends Component {
    public Behaviour() {
        System.out.println("Behaviour constructor called");
    }
}

class MonoBehaviour extends Behaviour {
    public MonoBehaviour() {
        super();
        System.out.println("MonoBehaviour constructor called");
    }
}

public class Main {
    public static void main(String[] args) {
        MonoBehaviour monoBehaviour = new MonoBehaviour();
    }
}
