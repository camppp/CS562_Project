template <typename Real>
Real CalculateSquaredDistance(const Triangle3<Real>* mTriangle, Real t, const Vector3<Real>& velocity1, const Segment3<Real>* mSegment) {
    // Calculate the moved vertices of the triangle
    Vector3<Real> movedV0 = mTriangle->V[0] + t * velocity1;
    Vector3<Real> movedV1 = mTriangle->V[1] + t * velocity1;
    Vector3<Real> movedV2 = mTriangle->V[2] + t * velocity1;

    // Create the moved segment and triangle
    Segment3<Real> movedSeg(mSegment->Center + t * mSegment->Direction, mSegment->Direction, mSegment->Extent);
    Triangle3<Real> movedTriangle(movedV0, movedV1, movedV2);

    // Calculate the squared distance between the moved segment and triangle
    return DistSegment3Triangle3<Real>(movedSeg, movedTriangle).GetSquared();
}
