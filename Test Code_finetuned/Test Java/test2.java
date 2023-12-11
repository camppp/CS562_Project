import java.util.HashSet;
import java.util.Set;

public class DuplicateChecker {
    public static boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.contains(num)) {
                return true; // Found a duplicate
            }
            set.add(num);
        }
        return false; // No duplicates found
    }
}