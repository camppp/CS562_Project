java
public class AlertManager {
    private int ticker;

    public void dismiss() {
        Ui.instance.alertManager.dismiss();
    }

    public void incrementTicker() {
        ticker++;
    }
}
