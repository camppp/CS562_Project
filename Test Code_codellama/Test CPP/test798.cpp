class ParameterCount_t {
private:
    int pid;
    int length;

public:
    ParameterCount_t(int pid, int length) {
        this->pid = pid;
        this->length = length;
    }

    int getPID() {
        return pid;
    }

    int getLength() {
        return length;
    }
};
