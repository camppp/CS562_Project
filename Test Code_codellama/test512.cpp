public class TimeRangeManager {
    private final Object lock = new Object();
    private final List<Long> protectedRanges = new ArrayList<>();
    private final List<Long> unprotectedRanges = new ArrayList<>();

    public TimeRangeManager() {
        // Initialize the protected and unprotected ranges
        protectedRanges.add(Long.MIN_VALUE);
        unprotectedRanges.add(Long.MAX_VALUE);
    }

    public void protectTimeRange(long t_min) {
        synchronized (lock) {
            // Check if the range is already protected
            if (protectedRanges.contains(t_min)) {
                return;
            }

            // Add the range to the protected ranges
            protectedRanges.add(t_min);

            // Remove the range from the unprotected ranges
            unprotectedRanges.remove(t_min);
        }
    }

    public void unprotectTimeRange(long t_min) {
        synchronized (lock) {
            // Check if the range is already unprotected
            if (!protectedRanges.contains(t_min)) {
                return;
            }

            // Remove the range from the protected ranges
            protectedRanges.remove(t_min);

            // Add the range to the unprotected ranges
            unprotectedRanges.add(t_min);
        }
    }

    public void runWhenUnprotected(long t) {
        synchronized (lock) {
            // Check if the range is already unprotected
            if (unprotectedRanges.contains(t)) {
                return;
            }

            // Wait until the range becomes unprotected
            while (!unprotectedRanges.contains(t)) {
                try {
                    lock.wait();
                } catch (InterruptedException e) {
                    // Handle the exception
                }
            }

            // Run the code when the range becomes unprotected
            // ...
        }
    }
}
