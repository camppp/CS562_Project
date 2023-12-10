#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreVector2.h>

class Ball {
public:
    Ball(Ogre::Entity* ballEntity, Ogre::SceneManager* scnMgr);
    void update(float deltaTime);
    void applyForce(Ogre::Vector2 force);
    void handleScreenCollision(int screenWidth, int screenHeight);

private:
    Ogre::SceneNode* ballShape;
    Ogre::Vector2 ballVelocity;
    Ogre::Vector2 ballPosition;
};

Ball::Ball(Ogre::Entity* ballEntity, Ogre::SceneManager* scnMgr) {
    // Create ball
    // Set position, size
    ballShape = scnMgr->getRootSceneNode()->createChildSceneNode();
    ballShape->setPosition(0, 20, 0); // about mid screen
    ballShape->setScale(0.1f, 0.1f, 0.1f);
    ballShape->attachObject(ballEntity);

    // Set starting velocity/speed and position to zero
    ballVelocity = Ogre::Vector2(0.0f, 0.0f);
    ballPosition = Ogre::Vector2(0.0f, 0.0f);
}

void Ball::update(float deltaTime) {
    // Update ball's position based on its velocity and time
    ballPosition += ballVelocity * deltaTime;
    ballShape->setPosition(ballPosition.x, 20, ballPosition.y); // assuming Y is the vertical axis
}

void Ball::applyForce(Ogre::Vector2 force) {
    // Implement a method to apply a force to the ball, which will change its velocity
    ballVelocity += force;
}

void Ball::handleScreenCollision(int screenWidth, int screenHeight) {
    // Implement a method to handle collisions with the boundaries of the screen
    if (ballPosition.x < 0 || ballPosition.x > screenWidth) {
        ballVelocity.x *= -1; // Reverse the x component of velocity
    }
    if (ballPosition.y < 0 || ballPosition.y > screenHeight) {
        ballVelocity.y *= -1; // Reverse the y component of velocity
    }
}
