#include <cmath>
#include <cms/Exception.h>
#include <FreeTrajectoryState.h>
#include <TrajectoryStateOnSurface.h>

TrajectoryStateOnSurface extrapolate(const FreeTrajectoryState& start) {
  // Check if the magnetic field is valid
  if (!magneticField_.isValid()) {
    throw cms::Exception("NotInitialized") << "Magnetic field is not valid";
  }

  // Check if the barrel cylinder is initialized
  if (!barrelCylinder_) {
    throw cms::Exception("NotInitialized") << "Barrel cylinder is not initialized";
  }

  // Check if the momentum magnitude is zero
  if (std::abs(start.momentum().mag()) < 1e-6) {
    return TrajectoryStateOnSurface();
  }

  // Extrapolate the state to the surface
  auto surface = barrelCylinder_->surface();
  auto extrapolatedState = surface.toGlobal(start.position(), start.momentum());

  return TrajectoryStateOnSurface(extrapolatedState, surface);
}
