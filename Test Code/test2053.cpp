java
public int f(int idxL, int idxR, int num, int l, int r, int[] pw) {
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        if (i > 0 || idxL > 0) {
            int val = num + i * pw[idxL];
            if (idxL < idxR) {
                val += i * pw[idxR];
            }
            ans += f(idxL + 1, idxR - 1, val, l, r, pw);
        }
    }
    return ans;
}
