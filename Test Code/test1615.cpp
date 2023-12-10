int customSearch(int arr[], int size, int target) {
    bool flg = false;
    int newfrom = 0;
    int i = 0;
    while (i < size) {
        if (arr[i] == target) {
            flg = true;
            newfrom = i;
            break;
        }
        i++;
    }
    if (flg) {
        return newfrom;
    } else {
        return -1;
    }
}
