#include <iostream>
#include <string>

struct TextFormat {
    std::string txt;
    std::string color;
    bool bold;
    bool italic;
    bool underline;
    bool strikethrough;

    TextFormat setText(const std::string& txt) {
        if (txt.empty()) {
            // Set default text
            this->txt = "Default Text";
        } else {
            this->txt = txt;
        }

        return *this;
    }

    TextFormat setColor(const std::string& color) {
        this->color = color;
        return *this;
    }

    TextFormat setBold(bool bold) {
        this->bold = bold;
        return *this;
    }

    TextFormat setItalic(bool italic) {
        this->italic = italic;
        return *this;
    }

    TextFormat setUnderline(bool underline) {
        this->underline = underline;
        return *this;
    }

    TextFormat setStrikethrough(bool strikethrough) {
        this->strikethrough = strikethrough;
        return *this;
    }

    void displayFormat() {
        std::cout << "Text: " << this->txt << std::endl;
        std::cout << "Color: " << this->color << std::endl;
        std::cout << "Bold: " << this->bold << std::endl;
        std::cout << "Italic: " << this->italic << std::endl;
        std::cout << "Underline: " << this->underline << std::endl;
        std::cout << "Strikethrough: " << this->strikethrough << std::endl;
    }
};
