int shortestRepeatingPrefix(string a) {
    int len = a.length();
    for (int i = 0; i < len; i++) {
        if (len % (i + 1) == 0 && a[0] == a[i]) {
            bool bj = false;
            for (int j = 0; j + i + 1 < len; j++) {
                if (a[j] != a[j + 1 + i]) {
                    bj = true;
                    break;
                }
            }
            if (!bj) {
                return i + 1;
            }
        }
    }
    return -1;
}
