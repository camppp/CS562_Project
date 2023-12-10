java
public int findFirstPositive(int[] arr) {
    boolean[] seen = new boolean[arr.length + 1];

    for (int num : arr) {
        if (num > 0 && num <= arr.length) {
            seen[num] = true;
        }
    }

    for (int i = 1; i < seen.length; i++) {
        if (!seen[i]) {
            return i;
        }
    }

    return 0;
}
