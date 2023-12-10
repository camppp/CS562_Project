java
public class WelcomeNotificationManager {
    private Preferences preferences;

    public WelcomeNotificationManager(Preferences preferences) {
        this.preferences = preferences;
    }

    public void setWelcomeNotificationDismissed(boolean dismissed) {
        preferences.setBooleanPref("kWelcomeNotificationDismissed", dismissed);
    }

    public void setWelcomeNotificationDismissedLocal(boolean dismissedLocal) {
        preferences.setBooleanPref("kWelcomeNotificationDismissedLocal", dismissedLocal);
    }

    public void setWelcomeNotificationPreviouslyPoppedUp(boolean previouslyPoppedUp) {
        preferences.setBooleanPref("kWelcomeNotificationPreviouslyPoppedUp", previouslyPoppedUp);
    }

    public void setWelcomeNotificationExpirationTimestamp(long expirationTimestamp) {
        preferences.setInt64Pref("kWelcomeNotificationExpirationTimestamp", expirationTimestamp);
    }

    public boolean getWelcomeNotificationDismissed() {
        return preferences.getBooleanPref("kWelcomeNotificationDismissed");
    }

    public boolean getWelcomeNotificationDismissedLocal() {
        return preferences.getBooleanPref("kWelcomeNotificationDismissedLocal");
    }

    public boolean getWelcomeNotificationPreviouslyPoppedUp() {
        return preferences.getBooleanPref("kWelcomeNotificationPreviouslyPoppedUp");
    }

    public long getWelcomeNotificationExpirationTimestamp() {
        return preferences.getInt64Pref("kWelcomeNotificationExpirationTimestamp");
    }
}
