java
import java.util.ArrayList;
import java.util.List;

public class ServiceFilter {
    public List<String> filterServices(List<String> services, String pattern) {
        List<String> matchedServices = new ArrayList<>();
        for (String service : services) {
            if (isMatch(service, pattern)) {
                matchedServices.add(service);
            }
        }
        return matchedServices;
    }

    private boolean isMatch(String service, String pattern) {
        if (pattern.equals("*")) {
            return true;
        }
        if (pattern.isEmpty()) {
            return service.isEmpty();
        }
        if (pattern.charAt(0) == '*') {
            return isMatch(service, pattern.substring(1)) || (!service.isEmpty() && isMatch(service.substring(1), pattern));
        }
        if (!service.isEmpty() && (pattern.charAt(0) == '.' || pattern.charAt(0) == service.charAt(0))) {
            return isMatch(service.substring(1), pattern.substring(1));
        }
        return false;
    }

    public static void main(String[] args) {
        ServiceFilter serviceFilter = new ServiceFilter();
        List<String> services = List.of("glibc.*", "cckit.*", "books.*", "test.*", "*httpecho*");
        String pattern = "test.*";
        List<String> matchedServices = serviceFilter.filterServices(services, pattern);
        System.out.println("Matched Services: " + matchedServices);
    }
}
