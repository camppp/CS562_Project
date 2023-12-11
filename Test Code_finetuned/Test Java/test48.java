public class Buttons {
    private int maxCount;
    private int count;

    public Buttons(int maxCount) {
        this.maxCount = maxCount;
        this.count = 0;
    }

    public void press() {
        if (count < maxCount) {
            count++;
        }
    }

    public void reset() {
        count = 0;
    }

    public int getCount() {
        return count;
    }
}

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class ButtonsTest {

    @Test
    void testPress() {
        Buttons buttons = new Buttons(5);
        buttons.press();
        assertEquals(1, buttons.getCount());
        buttons.press();
        assertEquals(2, buttons.getCount());
        buttons.press();
        assertEquals(3, buttons.getCount());
        buttons.press();
        assertEquals(4, buttons.getCount());
        buttons.press();
        assertEquals(5, buttons.getCount());
        buttons.press();
        assertEquals(5, buttons.getCount());
    }

    @Test
    void testReset() {
        Buttons buttons = new Buttons(5);
        buttons.press();
        buttons.press();
        buttons.reset();
        assertEquals(0, buttons.getCount());
    }

    @Test
    void testGetCount() {
        Buttons buttons = new Buttons(5);
        assertEquals(0, buttons.getCount());
        buttons.press();
        assertEquals(1, buttons.getCount());
        buttons.press();
        assertEquals(2, buttons.getCount());
    }
}