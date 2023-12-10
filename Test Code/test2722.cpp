#include <iostream>

class FontManager {
private:
    IRenderObj* oldFont = nullptr;
    IRenderObj* currentFont = nullptr;

public:
    void SelectFont(IRenderObj* font) {
        if (font != nullptr) {
            oldFont = currentFont;
            currentFont = font;
            std::cout << "Font selected for rendering." << std::endl;
        } else {
            std::cerr << "Error: Invalid font object provided." << std::endl;
        }
    }

    void RestoreFont() {
        if (oldFont != nullptr) {
            currentFont = oldFont;
            oldFont = nullptr;
            std::cout << "Previous font restored." << std::endl;
        } else {
            std::cerr << "Error: No previous font to restore." << std::endl;
        }
    }
};

int main() {
    FontManager fontManager;
    IRenderObj* font1 = new IRenderObj();  // Assume font object creation
    IRenderObj* font2 = new IRenderObj();  // Assume font object creation

    fontManager.SelectFont(font1);
    fontManager.RestoreFont();
    fontManager.RestoreFont();  // Error: No previous font to restore.

    delete font1;
    delete font2;

    return 0;
}
