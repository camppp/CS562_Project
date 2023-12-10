class ConnectionChecker {
public:
    ConnectionChecker(bool initialStatus) {
        status = initialStatus;
    }

    void open() {
        status = true;
    }

    void close() {
        status = false;
    }

    string getStatus() {
        if (status) {
            return "opened";
        } else {
            return "closed";
        }
    }

private:
    bool status;
};
