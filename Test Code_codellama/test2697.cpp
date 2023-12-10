c
int simEmbRotateAroundAxis_matrix(const extIkReal* matrixIn, const extIkReal* axisVector, const extIkReal* axisPosition, extIkReal angle, extIkReal* matrixOut)
{
    // Initialize a C4X4Matrix from the input matrix
    C4X4Matrix mat(matrixIn);

    // Perform some initial operations
    mat.transpose();
    mat.invert();

    // Calculate the rotation matrix around the axis
    C4X4Matrix rotMat = C4X4Matrix::rotation(axisVector, angle);

    // Apply the rotation to the input matrix
    mat = rotMat * mat;

    // Store the resulting transformation matrix in the output array
    for (int i = 0; i < 12; i++)
    {
        matrixOut[i] = mat.get(i);
    }

    return 0;
}
