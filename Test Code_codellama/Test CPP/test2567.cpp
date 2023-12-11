public void merge(int[] nums0, int[] nums2, int low, int pos, int high) {
    int i = low, j = pos + 1, k = low;
    while (i <= pos && j <= high) {
        if (nums0[i] <= nums0[j]) {
            nums2[k++] = nums0[i++];
        } else {
            nums2[k++] = nums0[j++];
        }
    }
    while (i <= pos) {
        nums2[k++] = nums0[i++];
    }
    while (j <= high) {
        nums2[k++] = nums0[j++];
    }
}
