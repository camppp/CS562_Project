java
public class MergeSort {
    public void merge_sort(int[] nums1, int[] nums0, int low, int high) {
        if (low < high) {
            int pos = (low + high) / 2;
            merge_sort(nums1, nums0, low, pos);
            merge_sort(nums1, nums0, pos+1, high);
            merge(nums0, nums1, low, pos, high);
        }
    }

    public void merge(int[] nums0, int[] nums2, int low, int pos, int high) {
        int leftLength = pos - low + 1;
        int rightLength = high - pos;

        int[] leftArray = new int[leftLength];
        int[] rightArray = new int[rightLength];

        for (int i = 0; i < leftLength; i++) {
            leftArray[i] = nums0[low + i];
        }
        for (int j = 0; j < rightLength; j++) {
            rightArray[j] = nums0[pos + 1 + j];
        }

        int i = 0, j = 0, k = low;
        while (i < leftLength && j < rightLength) {
            if (leftArray[i] <= rightArray[j]) {
                nums2[k] = leftArray[i];
                i++;
            } else {
                nums2[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < leftLength) {
            nums2[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < rightLength) {
            nums2[k] = rightArray[j];
            j++;
            k++;
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};
        int[] aux = new int[arr.length];
        MergeSort sorter = new MergeSort();
        sorter.merge_sort(arr, aux, 0, arr.length - 1);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
