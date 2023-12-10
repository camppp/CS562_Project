bool Triangle::triangleIsIntersected(const Ray& ray, float& distAlongRayToHit, Point& hitPoint) const
{
    const float EPSILON = 0.000001f;
    Vector edge1 = vertex2 - vertex1;
    Vector edge2 = vertex3 - vertex1;
    Vector h = cross(ray.direction, edge2);
    float a = dot(edge1, h);

    if (a > -EPSILON && a < EPSILON) {
        return false;  // The ray is parallel to the triangle
    }

    float f = 1.0f / a;
    Vector s = ray.origin - vertex1;
    float u = f * dot(s, h);

    if (u < 0.0f || u > 1.0f) {
        return false;
    }

    Vector q = cross(s, edge1);
    float v = f * dot(ray.direction, q);

    if (v < 0.0f || u + v > 1.0f) {
        return false;
    }

    float t = f * dot(edge2, q);

    if (t > EPSILON) {
        distAlongRayToHit = t;
        hitPoint = ray.origin + ray.direction * t;
        return true;
    }

    return false;
}
