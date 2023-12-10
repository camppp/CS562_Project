IntersectionTestResult testIntersection(const Ray& ray) {
    IntersectionTestResult result;

    // Calculate the dot product of the ray direction and the plane normal
    float denom = dot(ray.direction, normal());

    // If the dot product is close to zero, the ray is parallel to the plane
    if (std::abs(denom) < EPSILON) {
        result.intersects = false;
        return result;
    }

    // Calculate the distance from the ray origin to the plane
    float t = dot(plane.point - ray.origin, normal()) / denom;

    // If the distance is negative, the intersection point is behind the ray origin
    if (t < 0) {
        result.intersects = false;
        return result;
    }

    // Calculate the intersection point
    result.intersectionPoint = ray.origin + t * ray.direction;
    result.intersects = true;

    return result;
}
