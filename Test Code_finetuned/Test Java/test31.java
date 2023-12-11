import java.util.ArrayList;
import java.util.List;
import java.util.RandomAccess;
import java.io.Serializable;
import java.util.function.Predicate;

public class AdapterDataSet<E extends BaseItem> extends ArrayList<E> implements List<E>, RandomAccess, Cloneable, Serializable {

    public int countItemsWithProperty(Predicate<? super E> predicate) {
        int count = 0;
        for (E item : this) {
            if (predicate.test(item)) {
                count++;
            }
        }
        return count;
    }
}