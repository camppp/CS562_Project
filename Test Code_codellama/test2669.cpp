// Component.java
public class Component {
    private boolean isComplete;

    public void componentComplete() {
        isComplete = true;
    }

    public boolean isComplete() {
        return isComplete;
    }
}

// GameEntity.java
public class GameEntity {
    private List<Component> components;

    public GameEntity() {
        components = new ArrayList<>();
    }

    public void addComponent(Component component) {
        components.add(component);
    }

    public void callComponentComplete() {
        for (Component component : components) {
            component.componentComplete();
        }
    }
}
