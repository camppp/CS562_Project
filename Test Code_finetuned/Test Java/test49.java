private static long idCounter = 0;

public synchronized void assignUniqueId() {
    if (this.msgId == null) {
        this.msgId = ++idCounter;
    }
}