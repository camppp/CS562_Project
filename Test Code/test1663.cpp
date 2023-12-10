#include <iostream>

struct TextFormat {
    std::string txt;
    std::string color;
    bool bold;
    bool italic;
    bool underline;
    bool strikethrough;

    void setColor(const std::string& color) {
        this->color = color;
    }

    void setBold(bool bold) {
        this->bold = bold;
    }

    void setItalic(bool italic) {
        this->italic = italic;
    }

    void setUnderline(bool underline) {
        this->underline = underline;
    }

    void setStrikethrough(bool strikethrough) {
        this->strikethrough = strikethrough;
    }

    void displayFormat() {
        std::cout << txt << ":" << color << ":" << bold << ":" << italic << ":" << underline << ":" << strikethrough << std::endl;
    }
};

int main() {
    TextFormat ft;
    ft.setColor("Red");
    ft.setBold(true);
    ft.setItalic(false);
    ft.setUnderline(true);
    ft.setStrikethrough(false);
    ft.displayFormat();

    return 0;
}
