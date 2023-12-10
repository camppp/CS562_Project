cocos2d::Vec2 calculateImagePosition(const std::string& imageName) {
    // Get the visible size of the screen
    cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();

    // Calculate the position for centering the image
    float posX = visibleSize.width / 2;
    float posY = visibleSize.height / 2;

    return cocos2d::Vec2(posX, posY);
}
