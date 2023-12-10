void Ask(int id) {
    if (vis[id]) return; // Assuming vis[] is a boolean array to track visited ids
    cout << "? " << id << endl; // Output the question mark followed by the id
    fflush(stdout); // Flush the output buffer to ensure the message is sent

    int cnt, x;
    cin >> cnt; // Read the count of integers in the response
    if (cnt == 0) exit(0); // Terminate if the count is 0

    while (cnt--) {
        cin >> x; // Read the space-separated integers from the response
        // Process the retrieved integer(s) as needed
    }
}
