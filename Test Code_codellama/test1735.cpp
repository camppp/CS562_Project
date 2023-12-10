struct IntersectionTestResult {
    bool intersects;
    Vector3 intersectionPoint;
};

IntersectionTestResult testIntersection(const Ray& ray, const Plane& plane) {
    // Calculate the dot product of the ray direction and the plane normal
    float dotProduct = dot(ray.direction, plane.normal);

    // If the dot product is zero, the ray is parallel to the plane and does not intersect
    if (dotProduct == 0) {
        return {false, {}};
    }

    // Calculate the distance from the ray origin to the plane
    float distance = dot(ray.origin - plane.origin, plane.normal) / dotProduct;

    // If the distance is negative, the ray origin is behind the plane and does not intersect
    if (distance < 0) {
        return {false, {}};
    }

    // Calculate the intersection point
    Vector3 intersectionPoint = ray.origin + distance * ray.direction;

    // Return the intersection result
    return {true, intersectionPoint};
}
