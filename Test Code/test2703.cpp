java
public boolean isElementGreaterThanAdjacent(int[] arr) {
    if (arr.length < 3) {
        return false; // Array should have at least 3 elements to have adjacent elements
    }
    
    for (int i = 1; i < arr.length - 1; i++) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            return true; // Found an element greater than both its adjacent elements
        }
    }
    
    return false; // No element found greater than both its adjacent elements
}
