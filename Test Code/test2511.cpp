class Actor {
public:
    void BeginPlay() {
        // Perform initialization tasks
    }
};

class Super : public Actor {
public:
    void BeginPlay() {
        Actor::BeginPlay();  // Call the Actor's BeginPlay method
        // Additional initialization tasks for Super class
    }
};
