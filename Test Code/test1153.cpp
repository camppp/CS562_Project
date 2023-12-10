void updateProbabilities(double c[N][N], int x, int y, double prob, double probRight, double probUp, double probLeft, int N) {
    // right
    if(x != N-1 && isValid(x+1, y, N))
        c[x+1][y] += prob * probRight;
    else
        c[x][y] += prob * probRight;
    // up
    if(y != 0 && isValid(x, y-1, N))
        c[x][y-1] += prob * probUp;
    else
        c[x][y] += prob * probUp;
    // left
    if(x != 0 && isValid(x-1, y, N))
        c[x-1][y] += prob * probLeft;
}

bool isValid(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}
