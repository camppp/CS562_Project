bool PlayScene::choice(QString statue)
{
    bool isChoosed = false;
    int score = 0;

    // Assuming there is a predefined mapping of statues to their respective scores
    QMap<QString, int> statueScores = {
        {"Statue1", 10},
        {"Statue2", 5},
        {"Statue3", 8}
        // Add more statues and their scores as needed
    };

    // Check if the chosen statue exists in the mapping
    if (statueScores.contains(statue)) {
        isChoosed = true;
        score = statueScores.value(statue);
        // Update the game's score with the calculated score
        updateScore(score);
    }

    return isChoosed;
}
