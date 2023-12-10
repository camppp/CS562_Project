c++
int countUniqueElements(int arr[], int size) {
    int uniqueCount = 0;
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueCount++;
        }
    }
    return uniqueCount;
}
