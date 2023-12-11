import com.google.common.collect.Multiset;

import java.util.HashSet;
import java.util.Set;

public Set<String> filterResources(Multiset<String> executionCounts, double threshold) {
    Set<String> authorized = new HashSet<>();
    double avg = getAverage(executionCounts);
    for (String res : executionCounts.elementSet()) {
        if (executionCounts.count(res) >= threshold * avg) {
            authorized.add(res);
        }
    }
    return authorized;
}