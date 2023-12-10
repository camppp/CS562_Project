#include <vector>
#include <memory>

class Font {
    // Define the Font class as per the requirements
};

#include "PX2FontManager.inl"

class FontManager {
public:
    using FontPtr = std::shared_ptr<Font>;

    void AddFont(const FontPtr& font) {
        mFonts.push_back(font);
    }

    void RemoveFont(const FontPtr& font) {
        auto it = std::find(mFonts.begin(), mFonts.end(), font);
        if (it != mFonts.end()) {
            mFonts.erase(it);
        }
    }

    FontPtr GetDefaultFont() const {
        return mDefaultFont;
    }

    void SetDefaultFont(const FontPtr& font) {
        mDefaultFont = font;
    }

    size_t GetNumFonts() const {
        return mFonts.size();
    }

    FontPtr GetFontAt(size_t index) const {
        if (index < mFonts.size()) {
            return mFonts[index];
        }
        return nullptr; // or throw an exception
    }

private:
    FontPtr mDefaultFont;
    std::vector<FontPtr> mFonts;
};
