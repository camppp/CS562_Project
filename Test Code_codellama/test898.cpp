#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreVector2.h>

class Ball {
public:
    Ball(Ogre::Entity* ballEntity, Ogre::SceneManager* scnMgr) {
        ballShape = scnMgr->createSceneNode();
        ballShape->attachObject(ballEntity);
        ballVelocity = Ogre::Vector2(0, 0);
        ballPosition = Ogre::Vector2(0, 0);
    }

    void update(float deltaTime) {
        // Update the ball's position based on its velocity and time
        ballPosition += ballVelocity * deltaTime;

        // Handle collisions with the boundaries of the screen
        handleScreenCollision(ballPosition, ballVelocity);
    }

    void applyForce(Ogre::Vector2 force) {
        // Apply the force to the ball's velocity
        ballVelocity += force;
    }

    void handleScreenCollision(int screenWidth, int screenHeight) {
        // Check for collisions with the boundaries of the screen
        if (ballPosition.x < 0 || ballPosition.x > screenWidth) {
            // Reflect the ball's velocity on the x-axis
            ballVelocity.x = -ballVelocity.x;
        }

        if (ballPosition.y < 0 || ballPosition.y > screenHeight) {
            // Reflect the ball's velocity on the y-axis
            ballVelocity.y = -ballVelocity.y;
        }
    }

private:
    Ogre::SceneNode* ballShape;
    Ogre::Vector2 ballVelocity;
    Ogre::Vector2 ballPosition;
};
