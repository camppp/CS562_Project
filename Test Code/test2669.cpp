java
// Component class
class Component {
    void componentComplete() {
        // Implementation of component completion logic
    }
}

// GameEntity class
class GameEntity {
    List<Component> components;

    public GameEntity() {
        components = new ArrayList<>();
    }

    public void addComponent(Component component) {
        components.add(component);
    }

    public void completeAllComponents() {
        for (Component component : components) {
            component.componentComplete();
        }
    }
}
