import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class SubscriptionManager {
    private Map<UUID, Subscription> subscriptions;

    public SubscriptionManager() {
        subscriptions = new HashMap<>();
    }

    public Subscription createSubscription(String userId) {
        Subscription subscription = new Subscription();
        subscription.setUserId(userId);
        subscription.setId(UUID.randomUUID());
        subscriptions.put(subscription.getId(), subscription);
        return subscription;
    }

    public Subscription getSubscriptionById(UUID id) {
        return subscriptions.get(id);
    }
}