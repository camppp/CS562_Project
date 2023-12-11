#include "PX2FontManager.inl"

class FontManager {
public:
    using FontPtr = std::shared_ptr<Font>;

    // Add a font to the manager
    void AddFont(const FontPtr& font) {
        mFonts.push_back(font);
    }

    // Remove a font from the manager
    void RemoveFont(const FontPtr& font) {
        auto it = std::find(mFonts.begin(), mFonts.end(), font);
        if (it != mFonts.end()) {
            mFonts.erase(it);
        }
    }

    // Get the default font
    FontPtr GetDefaultFont() const {
        return mDefaultFont;
    }

    // Set the default font
    void SetDefaultFont(const FontPtr& font) {
        mDefaultFont = font;
    }

    // Get the number of fonts in the manager
    size_t GetNumFonts() const {
        return mFonts.size();
    }

    // Get a font at a specific index
    FontPtr GetFontAt(size_t index) const {
        return mFonts[index];
    }

private:
    FontPtr mDefaultFont;
    std::vector<FontPtr> mFonts;
};
