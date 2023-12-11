Real DistSegment3Triangle3<Real>::calculateSquaredDistance(const Triangle3<Real>* mTriangle, Real t, const Vector3<Real>& velocity1, const Segment3<Real>* mSegment)
{
    // Calculate the position of the triangle at time t
    Vector3<Real> trianglePosition = mTriangle->getPosition() + t * velocity1;

    // Calculate the position of the segment at time t
    Vector3<Real> segmentPosition = mSegment->getPosition() + t * velocity1;

    // Calculate the squared distance between the triangle and the segment
    Real squaredDistance = (trianglePosition - segmentPosition).squaredNorm();

    // Calculate the squared distance between the triangle and the segment's endpoints
    Real squaredDistance1 = (trianglePosition - mSegment->getEndpoint1()).squaredNorm();
    Real squaredDistance2 = (trianglePosition - mSegment->getEndpoint2()).squaredNorm();

    // Return the minimum squared distance
    return std::min(squaredDistance, std::min(squaredDistance1, squaredDistance2));
}
