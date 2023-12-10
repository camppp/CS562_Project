int countAdditions(int X, int Y, int Z) {
    int sum = 0, cnt = 0;
    while(true) {
        sum += Y + Z;
        if (sum + Z > X) break;
        cnt++;
    }
    return cnt;
}
