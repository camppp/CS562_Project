long long RetrieveExpirationTime(void* Context, int GetExpirationTime) {
    if (GetExpirationTime) {
        // Assuming the expiration time is stored in the context
        // Replace the following line with the actual logic to retrieve the expiration time
        long long expirationTime = *(long long*)Context; // Example: Assuming expiration time is stored as a long long in the context
        return expirationTime;
    } else {
        return -1; // Or any appropriate message indicating that the expiration time is not requested
    }
}
