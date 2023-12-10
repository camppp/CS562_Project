void CalculateScore(GameInstance* instance)
{
    if (instance->gameState == isGamePlay)
    {
        if (instance->currentSecond == 60)
        {
            instance->score++;
            instance->currentSecond = 0;
        }
    }
}
