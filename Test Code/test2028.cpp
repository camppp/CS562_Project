bool PlayScene::choice(QString statue)//设选择点并统计得分
{
    bool isChoosed = false;

    // 如果玩家选择了特定的雕像，则将其设置为true
    if (statue == "特定的雕像") {
        isChoosed = true;
        // 计算玩家的得分并更新游戏的得分
        score += 10;
    }

    return isChoosed;
}
