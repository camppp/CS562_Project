public int countItemsWithProperty(Predicate<? super E> predicate) {
    int count = 0;
    for (E item : this) {
        if (predicate.test(item)) {
            count++;
        }
    }
    return count;
}