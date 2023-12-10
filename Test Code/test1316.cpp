void ListboxTextItem::setFont(const String& font_name)
{
    Font* font = &FontManager::getSingleton().get(font_name);
    setFont(font);
}
