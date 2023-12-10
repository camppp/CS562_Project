java
import java.util.LinkedList;

public class HashTable {
    private LinkedList<String>[] table;

    public HashTable(int size) {
        table = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList<>();
        }
    }

    public void insert(int hf, String record) {
        int index = hf % table.length;
        if (table[index] == null) {
            table[index] = new LinkedList<>();
        }
        table[index].add(record);
    }
}
