bool Triangle::triangleIsIntersected(const Ray& ray, float& distAlongRayToHit, Point& hitPoint) const
{
   // Calculate the dot product of the ray direction and the triangle normal
   float rayDirDotNormal = dot(ray.direction, faceNormal);

   // If the dot product is close to 0, the ray is parallel to the triangle plane and does not intersect
   if (abs(rayDirDotNormal) < 0.0001)
   {
      return false;
   }

   // Calculate the distance from the ray origin to the triangle plane
   float rayOriginToPlaneDist = dot(ray.origin, faceNormal) / rayDirDotNormal;

   // Calculate the intersection point on the triangle plane
   Point intersectionPoint = ray.origin + ray.direction * rayOriginToPlaneDist;

   // Check if the intersection point is inside the triangle
   if (!isPointInsideTriangle(intersectionPoint))
   {
      return false;
   }

   // Calculate the distance along the ray to the intersection point
   distAlongRayToHit = rayOriginToPlaneDist;

   // Set the hit point to the intersection point
   hitPoint = intersectionPoint;

   return true;
}
