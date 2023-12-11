import java.util.HashMap;
import java.util.Map;

public class VotingSystem {
    private Map<String, Integer> votes;

    public VotingSystem() {
        this.votes = new HashMap<>();
    }

    public void vote(String candidate) {
        if (votes.containsKey(candidate)) {
            votes.put(candidate, votes.get(candidate) + 1);
        } else {
            votes.put(candidate, 1);
        }
    }

    public boolean hasVoted(String candidate) {
        return votes.containsKey(candidate) && votes.get(candidate) > 0;
    }
}