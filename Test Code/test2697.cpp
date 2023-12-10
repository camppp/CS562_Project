int simEmbRotateAroundAxis_matrix(const extIkReal* matrixIn, const extIkReal* axisVector, const extIkReal* axisPosition, extIkReal angle, extIkReal* matrixOut)
{
    if (!hasLaunched()) {
        return -1; // Return -1 if the function fails to launch
    }

    // Initialize C4X4Matrix and C7Vector from the input matrixIn
    C4X4Matrix mat;
    mat.copyFromInterface(matrixIn);
    C7Vector m(mat.getTransformation());

    // Initialize C3Vector from the axisVector
    C3Vector ax(axisVector);

    // Perform rotation around the specified axis by the given angle
    C7Vector result = m.rotateAroundAxis(ax, angle, axisPosition);

    // Store the resulting transformation matrix in the matrixOut array
    const extIkReal* resultMatrix = result.getMatrix();
    for (int i = 0; i < 12; i++) {
        matrixOut[i] = resultMatrix[i];
    }

    return 0; // Return 0 to indicate successful rotation
}
