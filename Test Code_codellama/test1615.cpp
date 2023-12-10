int customSearch(int arr[], int size, int target) {
    int newfrom = 0;
    bool flg = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            flg = true;
            newfrom = i;
            break;
        }
    }

    if (flg) {
        return newfrom;
    } else {
        return -1;
    }
}
