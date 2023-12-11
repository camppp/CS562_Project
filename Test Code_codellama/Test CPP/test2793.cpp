class TextNumberContainer {
private:
    string text;
    int num;

public:
    TextNumberContainer(string text, int num) {
        this->text = text;
        this->num = num;
    }

    string getText() {
        return text;
    }

    int getNum() {
        return num;
    }
};
