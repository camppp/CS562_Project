vector<int> MaxK(int arr[], int n, int k) {
    vector<int> result;
    deque<int> Q(k);
    int i = 0;
    
    // Process the first subarray of size k
    for (i; i < k; i++) {
        while (!Q.empty() && arr[i] >= arr[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    
    // Process the remaining subarrays
    for (i; i < n; i++) {
        result.push_back(arr[Q.front()]);  // Store the maximum element of the previous subarray
        
        // Remove elements outside the current subarray from the front of the deque
        while (!Q.empty() && Q.front() <= i - k) {
            Q.pop_front();
        }
        
        // Remove elements smaller than the current element from the back of the deque
        while (!Q.empty() && arr[i] >= arr[Q.back()]) {
            Q.pop_back();
        }
        
        Q.push_back(i);  // Add the current element to the deque
    }
    
    result.push_back(arr[Q.front()]);  // Store the maximum element of the last subarray
    
    return result;
}
