java
import java.util.PriorityQueue;

public class KthSmallestElement {
    public static int findKthSmallest(int[] arr, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        
        for (int num : arr) {
            maxHeap.offer(num);
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }
        
        return maxHeap.peek();
    }

    public static void main(String[] args) {
        int[] arr = {3, 1, 4, 2, 5};
        int k = 3;
        System.out.println(findKthSmallest(arr, k)); // Output: 3
    }
}
