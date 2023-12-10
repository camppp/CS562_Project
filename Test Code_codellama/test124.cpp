Vector3 CalculateRayPlaneIntersection(const Ray& ray, const Vector3& planePoint, const Vector3& planeNormal)
{
    // Calculate the distance from the ray origin to the plane
    float distance = ray.dir.Dot(planeNormal);

    // If the ray is parallel to the plane, there is no intersection
    if (distance == 0)
        return Vector3::Zero;

    // Calculate the intersection point
    Vector3 intersection = ray.origin + ray.dir * (planePoint - ray.origin).Dot(planeNormal) / distance;

    // Return the intersection point
    return intersection;
}
