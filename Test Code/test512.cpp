java
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class TimeRangeManager {
    private final Lock lock = new ReentrantLock();
    private final Condition unprotectedCondition = lock.newCondition();
    private long protectedTime = Long.MIN_VALUE;

    public TimeRangeManager() {
        // Constructor implementation
    }

    public void protectTimeRange(long t_min) {
        lock.lock();
        try {
            if (t_min > protectedTime) {
                protectedTime = t_min;
            }
        } finally {
            lock.unlock();
        }
    }

    public void unprotectTimeRange(long t_min) {
        lock.lock();
        try {
            if (t_min <= protectedTime) {
                protectedTime = Long.MIN_VALUE;
                unprotectedCondition.signalAll();
            }
        } finally {
            lock.unlock();
        }
    }

    public void runWhenUnprotected(long t) {
        lock.lock();
        try {
            while (t <= protectedTime) {
                unprotectedCondition.await();
            }
            // Perform the action when the time range is unprotected
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            lock.unlock();
        }
    }
}
