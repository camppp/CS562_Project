class FontManager {
public:
    FontManager() {
        // Initialize the font manager with the default font
        m_selectedFont = nullptr;
    }

    ~FontManager() {
        // Clean up the font manager
        if (m_selectedFont != nullptr) {
            delete m_selectedFont;
        }
    }

    void SelectFont(Font* font) {
        // Check if a font is already selected
        if (m_selectedFont != nullptr) {
            // Restore the previously selected font
            m_selectedFont->AfterPaint();
        }

        // Select the new font
        m_selectedFont = font;

        // Set the font for rendering
        m_selectedFont->SelectObject();
    }

    void RestoreFont() {
        // Check if a font is selected
        if (m_selectedFont != nullptr) {
            // Restore the previously selected font
            m_selectedFont->AfterPaint();
            m_selectedFont = nullptr;
        }
    }

private:
    Font* m_selectedFont;
};
