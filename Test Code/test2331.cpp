java
import java.util.LinkedList;
import java.util.Queue;

public class KolejkaGame {
    private Queue<Integer> queue;
    private boolean kolejSi;

    public KolejkaGame() {
        queue = new LinkedList<>();
        kolejSi = false; // Initially set to false
    }

    public void add(int element) {
        queue.add(element);
        kolejSi = !kolejSi; // Toggle the player after adding an element
    }

    public void remove() {
        if (!queue.isEmpty()) {
            queue.poll();
            kolejSi = !kolejSi; // Toggle the player after removing an element
        }
    }

    public boolean isGameOver() {
        return queue.isEmpty();
    }

    public boolean getCurrentPlayer() {
        return kolejSi;
    }
}
