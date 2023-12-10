#include <cmath>
#include <AZMathAPI.h>

bool GetQuadRayListIntersection(const AZ::Vector3& quadVertex1, const AZ::Vector3& quadVertex2, const AZ::Vector3& quadVertex3, const AZ::Vector3& quadVertex4,
                                const AZ::Vector3& rayOrigin, const AZ::Vector3& rayDirection, float rayLength, bool expectedResult,
                                AZ::Vector3& intersectionPoint, AZ::Vector3& intersectionNormal) {
    // Calculate the normal of the quad
    AZ::Vector3 quadNormal = (quadVertex2 - quadVertex1).Cross(quadVertex3 - quadVertex1).GetNormalized();

    // Calculate the intersection point with the quad
    float denominator = rayDirection.Dot(quadNormal);
    if (std::abs(denominator) > 0.0001f) {
        float t = (quadVertex1 - rayOrigin).Dot(quadNormal) / denominator;
        if (t >= 0 && t <= rayLength) {
            AZ::Vector3 intersection = rayOrigin + rayDirection * t;

            // Check if the intersection point is inside the quad
            AZ::Vector3 edge1 = quadVertex2 - quadVertex1;
            AZ::Vector3 edge2 = quadVertex3 - quadVertex2;
            AZ::Vector3 edge3 = quadVertex4 - quadVertex3;
            AZ::Vector3 edge4 = quadVertex1 - quadVertex4;

            AZ::Vector3 normal1 = edge1.Cross(intersection - quadVertex1);
            AZ::Vector3 normal2 = edge2.Cross(intersection - quadVertex2);
            AZ::Vector3 normal3 = edge3.Cross(intersection - quadVertex3);
            AZ::Vector3 normal4 = edge4.Cross(intersection - quadVertex4);

            if (normal1.Dot(quadNormal) >= 0 && normal2.Dot(quadNormal) >= 0 &&
                normal3.Dot(quadNormal) >= 0 && normal4.Dot(quadNormal) >= 0) {
                intersectionPoint = intersection;
                intersectionNormal = quadNormal;
                return (expectedResult == true);
            }
        }
    }
    return (expectedResult == false);
}
