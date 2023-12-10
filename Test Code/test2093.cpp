cocos2d::Vec2 calculateImagePosition(const std::string& imageName)
{
    // Get the size of the image
    cocos2d::Size imageSize = cocos2d::Sprite::create(imageName)->getContentSize();

    // Get the size of the screen
    cocos2d::Size screenSize = Director::getInstance()->getVisibleSize();

    // Calculate the position of the image
    float x = (screenSize.width - imageSize.width) / 2;
    float y = (screenSize.height - imageSize.height) / 2;

    // Return the position
    return cocos2d::Vec2(x, y);
}
