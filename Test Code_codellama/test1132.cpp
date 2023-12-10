class Game {
public:
    Game(SpriteBuilder spriteBuilder) {
        bat = Bat(spriteBuilder);
    }

    void startGame() {
        while (true) {
            Idle();
            // game logic here
        }
    }

private:
    Bat bat;
};
