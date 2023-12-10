java
public int climbStairs(int n) {
    int prev = 0;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        int tmp = prev;
        prev = cur;
        cur = tmp + cur;
    }
    return cur;
}
