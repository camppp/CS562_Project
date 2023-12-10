class String {
private:
    int refCount;
    char* data;

public:
    String(const char* str) {
        refCount = 1;
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    ~String() {
        delete[] data;
    }

    int refs() {
        return refCount;
    }

    void addRef() {
        refCount++;
    }

    void releaseRef() {
        refCount--;
    }
};
