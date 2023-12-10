public class KolejkaGame {
    private Queue<Integer> queue;
    private boolean kolejSi;

    public KolejkaGame() {
        queue = new LinkedList<>();
        kolejSi = false; // Initially set to false
    }

    public void add(int element) {
        queue.add(element);
    }

    public void remove() {
        queue.remove();
    }

    public boolean isGameOver() {
        return queue.isEmpty();
    }

    public boolean getCurrentPlayer() {
        return kolejSi;
    }
}
