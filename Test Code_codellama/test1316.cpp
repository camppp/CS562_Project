void ListboxTextItem::setFont(const String& font_name)
{
    // Retrieve the font object from the FontManager
    Font* font = FontManager::get()->get(font_name);

    // Set the font for the text item
    setFont(font);
}
