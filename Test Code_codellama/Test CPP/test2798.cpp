class Factory {
public:
    Factory(HexagonGame& hexagonGame, const glm::vec2& centerPos) : mHexagonGame(hexagonGame), mCenterPos(centerPos) {}

    Wall createWall(int side, float thickness, const SpeedData& speed, const SpeedData& curve = {}, float hueMod = 0) {
        // Create a new wall object
        Wall wall(mHexagonGame, mCenterPos, side, thickness, speed, curve, hueMod);

        // Add the wall to the game
        mHexagonGame.addWall(wall);

        return wall;
    }

private:
    HexagonGame& mHexagonGame;
    const glm::vec2& mCenterPos;
};
