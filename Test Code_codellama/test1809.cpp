class BackupItem {
private:
    string data;

public:
    BackupItem() : data("") {}

    void setData(string data) {
        if (data.length() > 256) {
            this->data = data.substr(0, 256);
        } else {
            this->data = data;
        }
    }

    string getData() {
        return data;
    }
};
