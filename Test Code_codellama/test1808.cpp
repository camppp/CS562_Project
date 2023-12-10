class CustomArray {
private:
    vector<int> arr;

public:
    CustomArray(int n) : arr(n) {}

    void change(int pos, int val) {
        arr[pos] = val;
    }

    int get(int l, int r) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += arr[i];
        }
        return sum;
    }
};
