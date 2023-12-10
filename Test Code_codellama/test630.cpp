class Str {
private:
    char* str;
    int length;

    void countLength(char* str) {
        int len = 0;
        while (*str != '\0') {
            len++;
            str++;
        }
        length = len;
    }

public:
    Str(char* input) {
        str = new char[strlen(input) + 1];
        strcpy(str, input);
        countLength(str);
    }

    ~Str() {
        delete[] str;
    }

    void printStr() {
        cout << str << endl;
    }

    int length() {
        return length;
    }

    char at(int pos) {
        return str[pos];
    }
};
