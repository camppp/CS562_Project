Pose2 calculateRotationTranslation(const std::vector<Point2Pair>& pairs) {
  // Calculate the cosine and sine of the angle between the two points
  double cos_angle = (pairs[0].first.x - pairs[0].second.x) / (pairs[0].first.x - pairs[0].second.x);
  double sin_angle = (pairs[0].first.y - pairs[0].second.y) / (pairs[0].first.y - pairs[0].second.y);

  // Calculate the rotation matrix
  Rot2 rotation = Rot2::fromAngle(std::atan2(sin_angle, cos_angle));

  // Calculate the translation vector
  Point2 translation = Point2(pairs[0].first.x - pairs[0].second.x, pairs[0].first.y - pairs[0].second.y);

  // Return the resulting rotation matrix and translation vector
  return Pose2(rotation, translation);
}
