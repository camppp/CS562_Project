TrajectoryStateOnSurface PropagateToMuon::extrapolate(const FreeTrajectoryState &start) const {
  if (!magfield_.isValid() || barrelCylinder_ == nullptr) {
    throw cms::Exception("NotInitialized")
        << "PropagateToMuon: You must call init(const edm::EventSetup &iSetup) before using this object.\n";
  }

  if (start.momentum().mag() == 0) {
    return TrajectoryStateOnSurface(); // Return an empty TrajectoryStateOnSurface object
  }

  // Add implementation for extrapolation based on the provided start state
  // ...

  // Return the extrapolated state
  return extrapolatedState;
}
