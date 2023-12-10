Mat3 ShapeSphere::InertiaTensor() const
{
    Mat3 tensor;
    float mass = GetMass();  // Assuming there is a method GetMass() to retrieve the mass of the sphere
    float radius = GetRadius();  // Assuming there is a method GetRadius() to retrieve the radius of the sphere

    float coefficient = 2.0f / 5.0f;
    float inertiaValue = coefficient * mass * radius * radius;

    // Inertia tensor for a sphere is a diagonal matrix with the same value along the diagonal
    tensor[0][0] = inertiaValue;
    tensor[1][1] = inertiaValue;
    tensor[2][2] = inertiaValue;

    return tensor;
}
