import java.util.Arrays;
import java.util.List;

public class MultipleEventContainsFilter {
    private List<String> eventContainsStrings;
    private boolean isAnd;

    public MultipleEventContainsFilter(String filterName, boolean isAnd, FilterFactory factory) {
        this.isAnd = isAnd;
    }

    public void setEventContainsString(String eventContainsString) {
        this.eventContainsStrings = Arrays.asList(eventContainsString.split(","));
    }

    public boolean passes(DefaultLogEvent event) {
        if (isAnd) {
            return eventContainsStrings.stream().allMatch(event.getMessage()::contains);
        } else {
            return eventContainsStrings.stream().anyMatch(event.getMessage()::contains);
        }
    }
}