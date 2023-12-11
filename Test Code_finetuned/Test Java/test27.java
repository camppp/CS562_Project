import java.io.Serializable;

public class ShortContainer implements Serializable {
    private static final long serialVersionUID = -911790554283478225L;
    private short count;

    public ShortContainer(short count) {
        this.count = count;
    }

    public void inc() {
        this.count++;
    }

    public void dec() {
        this.count--;
    }

    public void inc(short n) {
        this.count += n;
    }

    public short getCount() {
        return this.count;
    }
}