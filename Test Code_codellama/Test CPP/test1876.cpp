void Ask(int id) {
    cout << "? " << id << endl;
    int cnt;
    cin >> cnt;
    if (cnt == 0) {
        return;
    }
    vector<int> numbers(cnt);
    for (int i = 0; i < cnt; i++) {
        cin >> numbers[i];
    }
    // Use the numbers vector here
}
