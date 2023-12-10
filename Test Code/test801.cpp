#ifndef GAZEBO_RENDERING_CUSTOMPSSMSHADOWCAMERASETUP_HH_
#define GAZEBO_RENDERING_CUSTOMPSSMSHADOWCAMERASETUP_HH_

#include "gazebo/rendering/ogre_gazebo.h"
#include <OgreShadowCameraSetupPSSM.h>

namespace gazebo
{
  class CustomPSSMShadowCameraSetup : public Ogre::PSSMShadowCameraSetup
  {
  public:
    CustomPSSMShadowCameraSetup() : Ogre::PSSMShadowCameraSetup() {}

    void setSplitPoints(const Ogre::Real* splitPoints, size_t numSplits)
    {
      Ogre::PSSMShadowCameraSetup::setSplitPoints(splitPoints, numSplits);
    }

    void getShadowCamera(const Ogre::SceneManager* sm, const Ogre::Camera* cam, const Ogre::Viewport* vp, const Ogre::Light* light, Ogre::Camera* texCam, size_t iteration) const
    {
      Ogre::PSSMShadowCameraSetup::getShadowCamera(sm, cam, vp, light, texCam, iteration);
    }

    void calculateSplitPoints(size_t splitCount, Ogre::Real nearDist, Ogre::Real farDist, Ogre::Real lambda)
    {
      Ogre::PSSMShadowCameraSetup::calculateSplitPoints(splitCount, nearDist, farDist, lambda);
    }
  };
} // namespace gazebo

#endif // GAZEBO_RENDERING_CUSTOMPSSMSHADOWCAMERASETUP_HH_
