int InternalPartition(int aVector[], int aLow, int aHigh) {
    // Select the pivot element
    int pivot = aVector[aLow];

    // Create a stack to keep track of the sub-arrays
    stack<int> subArrays;

    // Initialize the lower and upper indices of the current sub-array
    int low = aLow + 1;
    int high = aHigh;

    // Loop until the lower and upper indices meet
    while (low <= high) {
        // If the current element is less than the pivot, push it onto the stack
        if (aVector[low] < pivot) {
            subArrays.push(low);
            low++;
        }
        // If the current element is greater than the pivot, push it onto the stack
        else if (aVector[low] > pivot) {
            subArrays.push(high);
            high--;
        }
        // If the current element is equal to the pivot, move on to the next element
        else {
            low++;
        }
    }

    // If the stack is not empty, pop the top element and swap it with the pivot
    if (!subArrays.empty()) {
        int top = subArrays.top();
        subArrays.pop();
        swap(aVector[top], aVector[aLow]);
    }

    // Return the index of the pivot element
    return aLow;
}
