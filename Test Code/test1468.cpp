java
import java.util.ArrayList;
import java.util.List;

public class NotificationSystem {
    private List<String> notifications;

    public NotificationSystem() {
        this.notifications = new ArrayList<>();
    }

    public void setNotification(String message) {
        notifications.add(message);
    }

    public void clean() {
        notifications.clear();
    }

    public void displayNotifications() {
        for (String notification : notifications) {
            System.out.println(notification);
        }
    }

    public static void main(String[] args) {
        NotificationSystem notificationSystem = new NotificationSystem();
        notificationSystem.setNotification("New message received");
        notificationSystem.setNotification("Meeting reminder: 3 PM");
        notificationSystem.displayNotifications();
        notificationSystem.clean();
        notificationSystem.displayNotifications();
    }
}
