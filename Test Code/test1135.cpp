void CalculateScore(GameInstance* instance) {
    instance->frames++;
    instance->currentSecond++;
    if (instance->currentSecond == 60 && instance->gameState == isGamePlay) {
        instance->score++;
        instance->currentSecond = 0;
    }
    Render();
}
