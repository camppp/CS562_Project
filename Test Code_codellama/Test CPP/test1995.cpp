mat4 transpose(const mat4& A)
{
    mat4 B;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            B(i, j) = A(j, i);
        }
    }
    return B;
}
