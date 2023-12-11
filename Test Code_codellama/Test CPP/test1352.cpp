bool GetQuadRayListIntersection(const AZ::Vector3& quadVertex1, const AZ::Vector3& quadVertex2, const AZ::Vector3& quadVertex3, const AZ::Vector3& quadVertex4,
                                const AZ::Vector3& rayOrigin, const AZ::Vector3& rayDirection, float rayLength, bool expectedResult,
                                AZ::Vector3& intersectionPoint, AZ::Vector3& intersectionNormal)
{
    // Calculate the plane equation of the quad
    float a = quadVertex1.GetX() - quadVertex2.GetX();
    float b = quadVertex1.GetY() - quadVertex2.GetY();
    float c = quadVertex1.GetZ() - quadVertex2.GetZ();
    float d = -a * quadVertex1.GetX() - b * quadVertex1.GetY() - c * quadVertex1.GetZ();

    // Calculate the dot product of the ray direction and the plane normal
    float dotProduct = rayDirection.GetX() * a + rayDirection.GetY() * b + rayDirection.GetZ() * c;

    // Check if the ray is parallel to the plane
    if (dotProduct == 0)
    {
        // The ray is parallel to the plane, so there is no intersection
        return false;
    }

    // Calculate the distance from the ray origin to the plane
    float distance = (d - rayOrigin.GetX() * a - rayOrigin.GetY() * b - rayOrigin.GetZ() * c) / dotProduct;

    // Check if the distance is within the ray length
    if (distance < 0 || distance > rayLength)
    {
        // The distance is outside the ray length, so there is no intersection
        return false;
    }

    // Calculate the intersection point
    intersectionPoint = rayOrigin + rayDirection * distance;

    // Calculate the intersection normal
    intersectionNormal = AZ::Vector3(a, b, c).GetNormalized();

    // Check if the intersection point is within the quad
    if (intersectionPoint.GetX() < quadVertex1.GetX() || intersectionPoint.GetY() < quadVertex1.GetY() || intersectionPoint.GetZ() < quadVertex1.GetZ() ||
        intersectionPoint.GetX() > quadVertex2.GetX() || intersectionPoint.GetY() > quadVertex2.GetY() || intersectionPoint.GetZ() > quadVertex2.GetZ() ||
        intersectionPoint.GetX() < quadVertex3.GetX() || intersectionPoint.GetY() < quadVertex3.GetY() || intersectionPoint.GetZ() < quadVertex3.GetZ() ||
        intersectionPoint.GetX() > quadVertex4.GetX() || intersectionPoint.GetY() > quadVertex4.GetY() || intersectionPoint.GetZ() > quadVertex4.GetZ())
    {
        // The intersection point is outside the quad, so there is no intersection
        return false;
    }

    // The intersection point is within the quad, so there is an intersection
    return true;
}
