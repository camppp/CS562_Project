import java.util.ArrayList;
import java.util.List;

// Interface for progress monitor listeners
interface ProgressMonitorListener {
    void taskStarted();
    void taskCompleted();
}

// Class for progress monitor
class ProgressMonitor {
    private List<ProgressMonitorListener> listeners = new ArrayList<>();

    // Add a listener to the progress monitor
    public void addProgressMonitorListener(ProgressMonitorListener listener) {
        listeners.add(listener);
    }

    // Remove a listener from the progress monitor
    public void removeProgressMonitorListener(ProgressMonitorListener listener) {
        listeners.remove(listener);
    }

    // Notify all listeners that a task has started
    public void startTask() {
        for (ProgressMonitorListener listener : listeners) {
            listener.taskStarted();
        }
    }

    // Notify all listeners that a task has been completed
    public void completeTask() {
        for (ProgressMonitorListener listener : listeners) {
            listener.taskCompleted();
        }
    }
}