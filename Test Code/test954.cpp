public void insert(int hf, String record) {
    // Determine the index for the new record using the hash function
    int index = hf(record);

    // Check if there is already a record at the determined index
    if (hashTable[index] != null) {
        // If there is already a record, add the new record to the linked list at that index
        hashTable[index].add(record);
    } else {
        // If there is no record at the determined index, create a new linked list and add the new record to it
        LinkedList<String> list = new LinkedList<>();
        list.add(record);
        hashTable[index] = list;
    }
}
