java
public class NotificationSystem {
    private List<String> notifications;

    public void setNotification(String notification) {
        notifications.add(notification);
    }

    public void clean() {
        notifications.clear();
    }

    public void displayNotifications() {
        for (String notification : notifications) {
            System.out.println(notification);
        }
    }
}
