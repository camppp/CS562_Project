Vector3 CalculateRayPlaneIntersection(const Ray& ray, const Vector3& planePoint, const Vector3& planeNormal) {
    float denominator = DotProduct(planeNormal, ray.dir);
    
    // Check if the ray is parallel to the plane
    if (abs(denominator) < EPSILON) {
        // Ray is parallel to the plane, no intersection
        return SpecialValue; // Replace SpecialValue with appropriate representation
    }
    
    Vector3 rayToPlane = planePoint - ray.origin;
    float t = DotProduct(rayToPlane, planeNormal) / denominator;
    
    // Check if the intersection point is behind the ray's origin
    if (t < 0) {
        // Intersection point is behind the ray's origin, no intersection
        return SpecialValue; // Replace SpecialValue with appropriate representation
    }
    
    // Calculate the intersection point
    Vector3 intersectionPoint = ray.origin + ray.dir * t;
    return intersectionPoint;
}
