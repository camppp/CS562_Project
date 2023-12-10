java
import java.util.HashMap;
import java.util.Map;

public class TimezoneCache {
    private String cachedValue;
    private String cachedTimezone;
    private Map<String, String> timezoneCache;

    public TimezoneCache() {
        this.timezoneCache = new HashMap<>();
    }

    public String computeValueBasedOnTimezone(String timezone) {
        if (timezone.equals(cachedTimezone)) {
            return cachedValue; // Return cached value if timezone remains the same
        } else {
            if (timezoneCache.containsKey(timezone)) {
                cachedValue = timezoneCache.get(timezone); // Retrieve cached value for the new timezone
            } else {
                // Compute value based on the new timezone
                cachedValue = computeValue(timezone);
                timezoneCache.put(timezone, cachedValue); // Cache the computed value for the new timezone
            }
            cachedTimezone = timezone; // Update the cached timezone
            return cachedValue;
        }
    }

    private String computeValue(String timezone) {
        // Your implementation to compute the value based on the given timezone
        return "Computed value for timezone: " + timezone;
    }
}
