class array {
private:
    int length;
    int size;
    int *a;

public:
    array(int length) {
        this->length = length;
        this->size = length * sizeof(int);
        this->a = new int[length];
    }

    ~array() {
        delete[] a;
    }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
