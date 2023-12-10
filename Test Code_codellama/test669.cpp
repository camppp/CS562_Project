class GameCharacter {
public:
    void updatePosition(float deltaTime) {
        positionX += speedX * deltaTime + 0.5 * accelerationX * deltaTime * deltaTime;
        speedX += accelerationX * deltaTime;
    }

private:
    float positionX;
    float speedX;
    float accelerationX;
};
