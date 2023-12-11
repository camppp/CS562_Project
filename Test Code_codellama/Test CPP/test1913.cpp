class Stream {
public:
    void push(long data) {
        checkedNext(data);
        // push the data onto the stream
    }

    void push(int data) {
        checkedNext(data);
        // push the data onto the stream
    }

    void push(double data) {
        checkedNext(data);
        // push the data onto the stream
    }

    void push(string data) {
        checkedNext(data);
        // push the data onto the stream
    }

private:
    void checkedNext(long data) {
        // perform some validation before pushing the data onto the stream
    }

    void checkedNext(int data) {
        // perform some validation before pushing the data onto the stream
    }

    void checkedNext(double data) {
        // perform some validation before pushing the data onto the stream
    }

    void checkedNext(string data) {
        // perform some validation before pushing the data onto the stream
    }
};

int main() {
    Stream stream;
    stream.push(10); // push an integer onto the stream
    stream.push(10.5); // push a double onto the stream
    stream.push("hello"); // push a string onto the stream
    return 0;
}
