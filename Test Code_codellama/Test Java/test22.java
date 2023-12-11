import java.util.ArrayList;
import java.util.List;

public class ProgressMonitor {
    private List<ProgressMonitorListener> listeners = new ArrayList<>();

    public void addProgressMonitorListener(ProgressMonitorListener listener) {
        listeners.add(listener);
    }

    public void removeProgressMonitorListener(ProgressMonitorListener listener) {
        listeners.remove(listener);
    }

    public void startTask() {
        for (ProgressMonitorListener listener : listeners) {
            listener.taskStarted();
        }
    }

    public void completeTask() {
        for (ProgressMonitorListener listener : listeners) {
            listener.taskCompleted();
        }
    }
}

public interface ProgressMonitorListener {
    void taskStarted();
    void taskCompleted();
}