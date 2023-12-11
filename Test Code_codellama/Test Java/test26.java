import java.io.Serializable;

public class ShortContainer implements Serializable {
    private static final long serialVersionUID = -911790554283478225L;

    private short count;

    public ShortContainer(short count) {
        this.count = count;
    }

    public void inc() {
        count++;
    }

    public void dec() {
        count--;
    }

    public void inc(short n) {
        count += n;
    }

    public short getCount() {
        return count;
    }
}